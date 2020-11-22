#include <QtTest>

// add necessary includes here

class SceneTest : public QObject
{
    Q_OBJECT

public:
    SceneTest();
    ~SceneTest();

private slots:
    void test_case1();

};

SceneTest::SceneTest()
{

}

SceneTest::~SceneTest()
{

}

void SceneTest::test_case1()
{

}

QTEST_APPLESS_MAIN(SceneTest)

#include "tst_scenetest.moc"
