#include "cityscene.hh"

cityScene::cityScene(QObject *parent) :
    QGraphicsScene(parent)
{
    initPlayField();
//    penguinTimer_.setInterval(100);
//    penguinTimer_.start();
    //    connect(&penguinTimer_, &QTimer::timeout, penguin_, );
}

void cityScene::keyPressEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat() && event->key() == Qt::Key_A){
        penguin_->setStatus(Penguin::STATUS::attack);
        return;
    }

    switch (event->key()) {
    case Qt::Key_Right:
        penguin_->setStatus(Penguin::STATUS::move);
        penguin_->setDirection(Penguin::DIRECTION::right);
        break;
    case Qt::Key_Left :
        penguin_->setStatus(Penguin::STATUS::move);
        penguin_->setDirection(Penguin::DIRECTION::left);
        break;
    case Qt::Key_Space :


        break;


    case Qt::Key_Down :

    default:
        break;
    }

}

void cityScene::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()){
        return;
    }

    switch (event->key()) {
    case Qt::Key_Right:
        penguin_->setStatus(Penguin::STATUS::stand);
        break;
    case Qt::Key_Left :
        penguin_->setStatus(Penguin::STATUS::stand);
        break;
    default:
        break;
    }

}


void cityScene::initPlayField()
{
    setSceneRect(0,0,3746, 531);

    penguin_ = new Penguin();
    penguin_->setPos(100,100);
    addItem(penguin_);

}
