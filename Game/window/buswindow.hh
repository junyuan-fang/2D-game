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

    //those methods are for testing
     QPushButton* getEndButton();
     QPushButton* getLeftButton();
     QPushButton* getRightButton();

signals:
    void selectedBus(QString busNumber);     


private:
    QString MapOfBusStop;
    void initWindow();
    Ui::BusWindow *ui;


};

#endif // BUSWINDOW_HH
