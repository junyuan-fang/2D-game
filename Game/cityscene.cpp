#include "cityscene.hh"

cityScene::cityScene(QObject *parent) :
    QGraphicsScene(parent),
    jumpAnimation_(new QPropertyAnimation(this))
{
    initPlayField();
    jumpAnimation_->setTargetObject(this);
    jumpAnimation_->setPropertyName("jumpPos");
    jumpAnimation_->setStartValue(0);
    jumpAnimation_->setKeyValueAt(0.5, 1);
    jumpAnimation_->setEndValue(0);
    jumpAnimation_->setDuration(800);
    // choose OutInQuad: fast at begining, slow at the middle(top) and fast at the end again
    jumpAnimation_->setEasingCurve(QEasingCurve::OutInQuad);


    penguinTimer_.setInterval(100);
    penguinTimer_.start();
    connect(&penguinTimer_, &QTimer::timeout, this, &cityScene::processMultipleKeys);
}

qreal cityScene::getJumpPos() const
{
    return jumpPos_;
}

void cityScene::setJumpPos(const qreal& jumpPos)
{
    if (jumpPos == jumpPos_){
        return;
    }
    jumpPos_ = jumpPos;

    emit jumpPosChanged(jumpPos_);
    qreal groundY = (groundLevel - penguin_->boundingRect().height() / 2);
    //m_player->setY(y);
    qreal y =groundY -jumpAnimation_->currentValue().toReal() * JUMP_FACTOR;
    penguin_->setY(y);
    penguinY_ = y;

}


void cityScene::keyPressEvent(QKeyEvent* event)
{   
    // only event is not auto repeated, add key to keyPressed
    if (!event->isAutoRepeat()){
        keysPressed.insert(event->key());
    }
}

void cityScene::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()){
        return;
    }
    keysPressed.remove(event->key());

}

void cityScene::processMultipleKeys()
{
    penguinTimer_.setInterval(100);
    // only 4 case: move right, move left, jump, jump and move right, jump and move left

    //if keysPressed is empty or has left key and right key at the same time, then set penguin standing status
    if (keysPressed.isEmpty() || (keysPressed.contains(Qt::Key_Left) && keysPressed.contains(Qt::Key_Right))){
        penguin_->setStatus(Penguin::STATUS::stand);
        return;
    }
    if (keysPressed.contains(Qt::Key_A)){
        penguinTimer_.setInterval(500);
        penguin_->setStatus(Penguin::STATUS::attack);
        keysPressed.remove(Qt::Key_A);
        return;
    }
//    if (keysPressed.contains(Qt::Key_Space) && keysPressed.contains(Qt::Key_Right)){
//        penguin_->setStatus(Penguin::STATUS::jump);
//        jumpPenguin();
//        penguin_->setDirection(Penguin::DIRECTION::right);
//        rightMovePenguin();
//        keysPressed.remove(Qt::Key_Space);
//        return;
//    }

//    if (keysPressed.contains(Qt::Key_Space) && keysPressed.contains(Qt::Key_Left)){
//        penguin_->setStatus(Penguin::STATUS::jump);
//        jumpPenguin();
//        penguin_->setDirection(Penguin::DIRECTION::left);
//        leftMovePenguin();
//        keysPressed.remove(Qt::Key_Space);
//        return;
//    }
    if (keysPressed.contains(Qt::Key_Space)){
        penguin_->setStatus(Penguin::STATUS::jump);
        jumpPenguin();
        keysPressed.remove(Qt::Key_Space);
    }

    if (keysPressed.contains(Qt::Key_Right)){
        if (penguinY_ == groundLevel - penguin_->boundingRect().height() / 2){
            penguin_->setStatus(Penguin::STATUS::move);
        }
        penguin_->setDirection(Penguin::DIRECTION::right);
        rightMovePenguin();
        return;
    }
    if (keysPressed.contains(Qt::Key_Left)){
        if (penguinY_ == groundLevel - penguin_->boundingRect().height() / 2){
            penguin_->setStatus(Penguin::STATUS::move);
        }
        penguin_->setDirection(Penguin::DIRECTION::left);
        leftMovePenguin();
    }
}


void cityScene::initPlayField()
{
    setSceneRect(0,0,CITY_WIDTH, CITY_HEIGHT);

    penguin_ = new Penguin();
    penguinY_ = groundLevel - penguin_->boundingRect().height() / 2;
    penguin_->setPos(penguinX_,penguinY_);
    addItem(penguin_);

}

// when penguin left move or right move, only change the x-coordinator
void cityScene::leftMovePenguin()
{
    penguin_->moveBy(-MOVE_FACTOR, 0);
}
void cityScene::rightMovePenguin()
{
    penguin_->moveBy(MOVE_FACTOR, 0);
}

// jumping changes the player's y-coordinator
void cityScene::jumpPenguin()
{
    if (QAbstractAnimation::Stopped == jumpAnimation_->state()) {
            jumpAnimation_->start();
    }
}
