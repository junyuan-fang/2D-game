#ifndef PENGUIN_HH
#define PENGUIN_HH
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<string>

class Penguin : public QGraphicsPixmapItem, public QObject
{
public:
    explicit Penguin(QGraphicsItem *parent = 0);

    // set penguin's direction (penguin has 2 direction: right and left)
    enum class DIRECTION {right, left};
    DIRECTION getDirection() const;
    void setDirection(DIRECTION direction);

    // set penguin's animation (stand, attack, move and die)
    enum class STATUS {stand, attack, move, die};
    STATUS getStatus() const;
    void setStatus(STATUS status);

    void animation();


private:
    // define how many frames that the animation contains
    int STAND_FRAME = 7;
    int ATTACK_FRAME = 8;
    int MOVE_FRAME = 5;
    int DIE_FRAME = 4;

    DIRECTION currentDirection_;
    QTransform transform_;

    STATUS currentStatus_;
    int frameIndex_;

    QTimer animationTimer_;


    void standAnimation();
    void moveAnimation();
    void attackAnimation();
    void dieAnimation();

};

#endif // PENGUIN_HH
