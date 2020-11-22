#include <QtTest>
#include <QDebug>

// add necessary includes here

class WindowTest : public QObject
{
    Q_OBJECT

public:
    WindowTest();
    ~WindowTest();

private slots:
    void test_case1();

};

WindowTest::WindowTest()
{

}

WindowTest::~WindowTest()
{

}

void WindowTest::test_case1()
{

}

QTEST_APPLESS_MAIN(WindowTest)

#include "tst_windowtest.moc"
