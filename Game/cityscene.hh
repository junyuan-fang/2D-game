#ifndef CITYSCENE_HH
#define CITYSCENE_HH

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QSet>
#include "penguin.hh"

class cityScene : public QGraphicsScene
{
    Q_OBJECT
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)
    // set jump property
    Q_PROPERTY(qreal jumpPos READ getJumpPos WRITE setJumpPos NOTIFY jumpPosChanged)

public:
    explicit cityScene(QObject *parent = 0);

    qreal getJumpPos() const;

    void setJumpPos(const qreal& jumpPos);

protected:

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void processMultipleKeys();

signals:
    void jumpPosChanged(qreal);

private:
    // initialize the city scene: display player, scene, etc.
    void initPlayField();

    QSet<int> keysPressed;

    // when move the penguin
    qreal MOVE_FACTOR = 10;
    qreal JUMP_FACTOR = 100;
    void rightMovePenguin();
    void leftMovePenguin();
    void jumpPenguin(); // when player jumpy





    // city width and height
    int CITY_WIDTH = 3746;
    int CITY_HEIGHT = 531;

    qreal groundLevel = 300;

    // define player: penguin
    Penguin* penguin_;
    QTimer penguinTimer_;
    // define player's position
    qreal penguinX_ = 100;
    qreal penguinY_;

    //QTimer penguinTimer_;
    qreal jumpPos_;
    QPropertyAnimation* jumpAnimation_;
    
};

#endif // CITYSCENE_HH
