#ifndef LOGINWINDOW_HH
#define LOGINWINDOW_HH

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_HH
