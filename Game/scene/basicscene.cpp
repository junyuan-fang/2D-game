#include "basicscene.hh"

#include <QDebug>

BasicScene::BasicScene(QObject *parent):
    QGraphicsScene(parent)
{
    dieTimer.stop();
    dieTimer.setInterval(500);
    jumpSound->setSource(QUrl("qrc:/music/music/jump.wav"));
    attackSound->setSource(QUrl("qrc:/music/music/attack.wav"));
    dieSound->setSource(QUrl("qrc:/music/music/die.wav"));

    connect(&dieTimer, &QTimer::timeout, [this](){
        changeScene(mCurrentScene, SceneType::Hospital);
        dieTimer.stop();
    });

}

void BasicScene::updateScene()
{
    mPlayer->updatePlayer();
    mPlayer->setY(mPlayer->mCurrentPosition.y());
    moveScene();
    updateItemState();
    //qDebug() << mPlayer->mCurrentPosition.x << "  " << mPlayer->mCurrentPosition.y;

    // if play's y > sceneHeight, then player fell into the trap
    // but don't need to play the die anamition, just play the sound
    // and emit the signal fellInTrap() and change the scene
    if (mPlayer->mCurrentPosition.y() > SceneHeight && !dieTimer.isActive()){
        mPlayer->mCurrentPosition.setY(-100);
        dieSound->play();
        dieTimer.start();
        qDebug() << "fell into the trap: " << QString::number(mCurrentScene);
        emit fellInTrap();
    }
}

void BasicScene::initScene()
{

}

void BasicScene::moveScene()
{

}

void BasicScene::updateItemState()
{

}


void BasicScene::changeWorldShift()
{
    int RightShiftBorder = width() - ShiftBorder;

    const int visiblePlayerPos = mPlayer->mCurrentPosition.x() - m_worldShift;
    const int newWorldShiftRight = visiblePlayerPos - RightShiftBorder;

    if (newWorldShiftRight > 0) {
        m_worldShift += newWorldShiftRight;
    }
    const int newWorldShiftLeft = ShiftBorder - visiblePlayerPos;
    if (newWorldShiftLeft > 0) {
        m_worldShift -= newWorldShiftLeft;
    }

    m_worldShift = qBound(0, m_worldShift, MaxWorldShift);

}


void BasicScene::applyParallax(qreal ratio, QGraphicsItem *item)
{
    item->setX(-ratio * (item->boundingRect().width() - width()));

}

qreal BasicScene::distanceBetweenPlayerAndItem(QVector2D itemPosition)
{
    qreal dx = mPlayer->mCurrentPosition.x() - itemPosition.x();
    qreal dy = mPlayer->mCurrentPosition.y() - itemPosition.y();
    return std::sqrt(dx*dx + dy*dy);
}

void BasicScene::keyPressEvent(QKeyEvent *event)
{
    //if player is not visible, then don't handle the keyPressEvent
    if(!mPlayer->isVisible()){
        return;
    }
    if (event->isAutoRepeat()){
        return;
    }
    switch (event->key()) {
    case Qt::Key_Right:
        mPlayer->mInputs[Player::KeyInput::GoRight] = true;
        mPlayer->changeDirection(Player::PlayerDirection::Right);
        mPlayer->changeState(Player::PlayerState::Walk);
        break;
    case Qt::Key_Left:
        mPlayer->mInputs[Player::KeyInput::GoLeft] = true;
        mPlayer->changeDirection(Player::PlayerDirection::Left);
        mPlayer->changeState(Player::PlayerState::Walk);
        break;
    case Qt::Key_Space:
        mPlayer->mInputs[Player::KeyInput::Jump] = true;
        jumpSound->play();
        break;
    case Qt::Key_A:
        mPlayer->mInputs[Player::KeyInput::Attack] = true;
        attackSound->play();
        mPlayer->changeState(Player::PlayerState::Attack);
        break;
    }

}

void BasicScene::keyReleaseEvent(QKeyEvent *event)
{
    //if player is not visible, then don't handle the keyReleaseEvent
    if(!mPlayer->isVisible()){
        return;
    }

    if (event->isAutoRepeat()){
        return;
    }
    switch (event->key()) {
    case Qt::Key_Right:
        mPlayer->mInputs[Player::KeyInput::GoRight] = false;
        break;
    case Qt::Key_Left:
        mPlayer->mInputs[Player::KeyInput::GoLeft] = false;
        break;
    case Qt::Key_Space:
        mPlayer->mInputs[Player::KeyInput::Jump] = false;
    case Qt::Key_A:
        mPlayer->mInputs[Player::KeyInput::Attack] = false;
        break;
    }
}

void BasicScene::initEnemys(QString enemyPath)
{
    QVector<QVector2D> enemyPosition = mPlayer->mCurrentMap->getEnemyPosition();
    auto iter = enemyPosition.begin();
    while (iter != enemyPosition.end()) {
        Enemy* enemy = new Enemy(enemyPath);
        enemy->setPosition(*iter);
        enemy->setPos(iter->x(), iter->y());
        enemy->setStartX(iter->x());
        enemy->setEndX(iter->x() + 5*TileWidth);
        enemys.append(enemy);
//        connect(enemy->hitEffect, &HitEffect::surviveEnemy, [enemy](){
//            //qDebug() << "survive";
//            enemy->setVisible(true);
//            enemy->changeStatus(Enemy::EnemyStatus::Walk);
//            enemy->hitEffectVisble(false);
//        });
        this->addItem(enemy);
        ++iter;
    }
}

// update enemy's position &
//check if player attack the enemy &
// check the collision between player and enemy
void BasicScene::updateEnemy()
{
    if (enemys.empty()){
        return;
    }
    for (int i = 0; i < enemys.length(); ++i){
        Enemy* enemy = enemys.at(i);
        enemy->updateEnemy();
        enemy->setX(enemy->getPosition().x()-m_worldShift);
        // process attack with player
        // if player press attack keyboard and distance between player and enemy < tileWidth
        if(mPlayer->mInputs[Player::KeyInput::Attack] && distanceBetweenPlayerAndItem(enemy->getPosition())<5*TileWidth){
            // if player's attack direction is same as enemy's direction
            if ((mPlayer->x() < enemy->x() && mPlayer->currentDirection() == Player::PlayerDirection::Right) ||
                (mPlayer->x() > enemy->x() && mPlayer->currentDirection() == Player::PlayerDirection::Left)){
                enemy->changeStatus(Enemy::EnemyStatus::Hit);
                continue;
            }
        }

        // if player collide with the enemy, send the signal "collideWithEnemy"
        // and change player's state and play the die sound and change the scene
        if (enemy->collidesWithItem(mPlayer) && enemy->isVisible()){
            mPlayer->changeState(Player::PlayerState::Die);
            enemy->setVisible(false);
            dieSound->play();
            dieTimer.start();
            //qDebug() <<"collide with enemy"<< QString::number(mCurrentScene);
            emit collideWithEnemy();
        }
    }
}

void BasicScene::surviveEnemys()
{
    //qDebug() << "surviveEnemys";
    // if the scene doesn't contain any enemy, then return
    if (enemys.empty()){
        return;
    }

    for (int i = 0; i < enemys.length(); ++i){

        enemys.at(i)->setVisible(true);
        enemys.at(i)->changeStatus(Enemy::EnemyStatus::Walk);
        for (auto hitEffect : enemys.at(i)->childItems()){
            // set enemy's child item(hit effect) invisible when surviving the enemys
            hitEffect->setVisible(false);
        }
    }
}

void BasicScene::reloadScene()
{
    mPlayer->mCurrentPosition.setX(mPlayer->mCurrentMap->getPlayerStartPosition().x());
    mPlayer->mCurrentPosition.setY(mPlayer->mCurrentMap->getPlayerStartPosition().y());
    mPlayer->setPos(mPlayer->mCurrentPosition.x(), mPlayer->mCurrentPosition.y());
    mPlayer->changeState(Player::PlayerState::Stand);
    mPlayer->setVisible(true);
}

