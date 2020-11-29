#include <QtTest>
#include <QDebug>
#include "../../Game/window/login.hh"
#include "../../Game/window/login.cpp"
#include "../../Game/gameview.hh"
#include "../../Game/window/buswindow.hh"
#include "../../Game/window/buswindow.cpp"

// add necessary includes here

class BusWindowTest:public QObject
{
    Q_OBJECT
public:
    explicit BusWindowTest();
    ~BusWindowTest();
private slots:
    void testGuiEndButton();
    void testGuiEndButton_data();
    //attention:Bus1's button is not available if not in airport
    void testGuiBusButtons();
    void testGuiBusButtons_data();
private:
    BusWindow* busWindow_test;

};

BusWindowTest::BusWindowTest()
{
    busWindow_test= new BusWindow("airport");

}
BusWindowTest::~BusWindowTest()
{
    delete busWindow_test;
}

//test all scene's buswindow end button
void BusWindowTest::testGuiBusButtons()
{
    QFETCH(QString,current_scene);
    QFETCH(QString,Right_Left_Button);
    if(Right_Left_Button=="LEFT"){
        QTest::mouseClick(busWindow_test->getLeftButton(),Qt::LeftButton);
    }
    else if (Right_Left_Button=="RIGHT") {
         QTest::mouseClick(busWindow_test->getRightButton(),Qt::LeftButton);
    }
    QVERIFY2(busWindow_test->get_pressed()==true,"to destnation by bus is failed");
}

void BusWindowTest::testGuiBusButtons_data()
{
    QTest::addColumn<QString>("current_scene");
    QTest::addColumn<QString>("Right_Left_Button");
    //    // Generating test cases for the test matrix
    QTest::newRow("Current scene : Airpot. Press:Left Button ")<<"airport"<<"LEFT";
    QTest::newRow("Current scene : Airpot. Press:Right Button ")<<"airport"<<"RIGHT";
    QTest::newRow("Current scene : University. Press:Left Button ")<<"university"<<"LEFT";
    QTest::newRow("Current scene : City. Press:Left Button ")<<"city"<<"RIGHT";
}

void BusWindowTest::testGuiEndButton()
{
    QFETCH(QString, current_scene);
    QFETCH(QTestEventList, event);
    busWindow_test= new BusWindow(current_scene);
    event.simulate(busWindow_test->getEndButton());
    //QTest::mouseClick(busWindow_test->getEndButton(),Qt::LeftButton);
    QVERIFY2(busWindow_test->close()==true,"Bus window is not closed");
}

void BusWindowTest::testGuiEndButton_data()
{
    QTest::addColumn<QString>("current_scene");
     QTest::addColumn<QTestEventList>("event");
     //creating GUI events
    QTestEventList list_click;
    list_click.addMouseClick(Qt::LeftButton);
    //    // Generating test cases for the test matrix
    QTest::newRow("Airpot")<<"airport"<<list_click;
    QTest::newRow("University")<<"university"<<list_click;
    QTest::newRow("City")<<"city"<<list_click;
}



//LoginWindowTest will handle the "ui" which "Login" also have, and test it
class LoginWindowTest :public QObject
{
    Q_OBJECT
public:
    explicit LoginWindowTest();
    ~LoginWindowTest();

private slots:
    void testGuiCancleButton();
    void testGuiStartButton();

private:
    Login* login_dialog;
    GameView* testView;
};

LoginWindowTest::LoginWindowTest()
{
    login_dialog = new Login;
    testView = new GameView;
    testView->close();//make sure testview was closed
    login_dialog->connect(login_dialog, &QDialog::accepted, testView, &GameView::startView);

}

LoginWindowTest::~LoginWindowTest()
{
    delete login_dialog;
    delete testView;
}

void LoginWindowTest::testGuiCancleButton()
{
    QTest::mouseClick(login_dialog->getCancleButton(),Qt::LeftButton);
    QVERIFY2(login_dialog->isVisible()== false,"Login dialog is not closed");
}

void LoginWindowTest::testGuiStartButton()
{
    QTest::mouseClick(login_dialog->getStartButton(),Qt::LeftButton);
    QVERIFY2(testView->getCurrentScene() == BasicScene::SceneType::Start ,"Game is not start");
}




int main(int argc, char *argv[])
{
    int status = 0;

    {
        QApplication app(argc, argv);
        LoginWindowTest ta;
        status |= QTest::qExec(&ta, argc, argv);
    }
    {
        QApplication app(argc, argv);
        BusWindowTest tb;
        status |= QTest::qExec(&tb, argc, argv);
    }

   return status;
}


#include "tst_windowtest.moc"

