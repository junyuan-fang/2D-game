#include "penguin.hh"
#include<QGraphicsView>

Penguin::Penguin(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent),
    currentDirection_(DIRECTION::right),
    currentStatus_(STATUS::stand),
    frameIndex_(0)
{

    animationTimer_.setInterval(100);
    animationTimer_.start();
    transform_.scale(-1,1);
    connect(&animationTimer_, &QTimer::timeout, this, &Penguin::animation);


}

Penguin::DIRECTION Penguin::getDirection() const
{
    return currentDirection_;

}

void Penguin::setDirection(Penguin::DIRECTION direction)
{
    if (currentDirection_ == direction){
        return;
    }
    // if direction changed, then mirror the image
    currentDirection_ = direction;
    transform_.scale(-1,1);

}

Penguin::STATUS Penguin::getStatus() const
{
    return currentStatus_;

}

void Penguin::setStatus(Penguin::STATUS status)
{
    if (currentStatus_ == status){
        return;
    }
    currentStatus_ = status;
    frameIndex_ = 0;
}

void Penguin::animation()
{
    switch (currentStatus_) {
    case STATUS::stand :
        standAnimation();
    break;

    case STATUS::move :
        moveAnimation();
        break;

    case STATUS::die :
        dieAnimation();
       break;
    case STATUS::attack:
        attackAnimation();
        break;

    }
}

void Penguin::standAnimation()
{
    if (frameIndex_ > STAND_FRAME){
        frameIndex_ = 0;
    }
    QString pixelPath = ":/penguin/penguin/stand/stand" + QString::number(frameIndex_) + ".png";
    QPixmap standPixel(pixelPath);
    setPixmap(standPixel);
    setOffset(-standPixel.width() / 2, -standPixel.height() / 2);
    setTransform(transform_);
    frameIndex_ += 1;

}

void Penguin::moveAnimation()
{
    if (frameIndex_ > MOVE_FRAME){
        frameIndex_ = 0;
    }
    QString pixelPath = ":/penguin/penguin/move/move" + QString::number(frameIndex_) + ".png";
    QPixmap movePixel(pixelPath);
    setPixmap(movePixel);
    setOffset(-movePixel.width() / 2, -movePixel.height() / 2);
    setTransform(transform_);
    frameIndex_ += 1;

}

void Penguin::attackAnimation()
{
    QString pixelPath = ":/penguin/penguin/attack/attack" + QString::number(frameIndex_) + ".png";
    QPixmap attackPixel(pixelPath);
    setPixmap(attackPixel);
    setOffset(-attackPixel.width() / 2, -attackPixel.height() / 2);
    setTransform(transform_);
    frameIndex_ += 1;
    if (frameIndex_ > ATTACK_FRAME){
        frameIndex_ = 0;
        currentStatus_ = STATUS::stand;
    }

}

void Penguin::dieAnimation()
{
    if (frameIndex_ > DIE_FRAME){
        frameIndex_ = 0;
    }
    QString pixelPath = ":/penguin/penguin/die/die" + QString::number(frameIndex_) + ".png";
    QPixmap diePixel(pixelPath);
    setPixmap(diePixel);
    setOffset(-diePixel.width() / 2, -diePixel.height() / 2);
    setTransform(transform_);
    frameIndex_ += 1;
}
