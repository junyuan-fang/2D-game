#ifndef CITYSCENE_HH
#define CITYSCENE_HH

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "penguin.hh"

class cityScene : public QGraphicsScene
{
    Q_OBJECT
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit cityScene(QObject *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    void initPlayField();
    Penguin* penguin_;
    QTimer penguinTimer_;
    
};

#endif // CITYSCENE_HH
