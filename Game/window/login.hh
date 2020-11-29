#ifndef LOGIN_HH
#define LOGIN_HH

#include <QDialog>
#include <QPushButton>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

    //Those methods are for testing
    QPushButton* getCancleButton();
    QPushButton* getStartButton();

private:
    Ui::Login *ui;
};

#endif // LOGIN_HH
