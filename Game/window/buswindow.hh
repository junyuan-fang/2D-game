#ifndef BUSWINDOW_HH
#define BUSWINDOW_HH

#include <QWidget>
#include <QPushButton>

namespace Ui {
class BusWindow;
}

class BusWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BusWindow(QString mapName, QWidget *parent = nullptr);
    ~BusWindow();
    void Test();
    //for testing
    QPushButton *getEndButton();
    QPushButton *getLeftButton();
    QPushButton *getRightButton();
    bool get_pressed();

signals:
    void selectedBus(QString busNumber);     


private:
    QString MapOfBusStop;
    void initWindow();
    Ui::BusWindow *ui;
    //for testing
    bool button_pressed_=false;



};

#endif // BUSWINDOW_HH
