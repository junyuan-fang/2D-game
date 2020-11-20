#ifndef TALKWINDOW_HH
#define TALKWINDOW_HH

#include <QWidget>

namespace Ui {
class TalkWindow;
}

class TalkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TalkWindow(QWidget *parent = nullptr);
    ~TalkWindow();

private:
    Ui::TalkWindow *ui;
};

#endif // TALKWINDOW_HH
