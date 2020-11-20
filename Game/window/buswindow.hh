#ifndef BUSWINDOW_HH
#define BUSWINDOW_HH

#include <QWidget>

namespace Ui {
class BusWindow;
}

class BusWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BusWindow(QWidget *parent = nullptr);
    ~BusWindow();

private:
    Ui::BusWindow *ui;
};

#endif // BUSWINDOW_HH
