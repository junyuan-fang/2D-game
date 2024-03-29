#include <QtTest>
#include <QTest>
#include <QVector2D>
#include <QString>
#include "gameview.hh"
#include "../Game/scene/basicscene.hh"
Q_DECLARE_METATYPE(BasicScene::SceneType);
// add necessary includes here
const QVector<QString> SCENE={"start","end","tampere","airpots","city","university","hospital","basic"};

class gameViewTest_none : public QObject
{
    Q_OBJECT

public:
    gameViewTest_none();
    ~gameViewTest_none();

private slots:
    void check_scene();
};
gameViewTest_none::gameViewTest_none()
{

}

gameViewTest_none::~gameViewTest_none()
{

}
void gameViewTest_none::check_scene()
{
}


class gameViewTest : public QObject
{
    Q_OBJECT

public:
    gameViewTest();
    ~gameViewTest();

private slots:
    void switch_scene();
    void switch_scene_data();

};

gameViewTest::gameViewTest()
{

}

gameViewTest::~gameViewTest()
{

}

void gameViewTest::switch_scene()
{
    // This method tests a row of the test matrix generated by the method switching_scene_data.
       // It is called automatically for each row of the matrix

    // Fetching data from the matrix, variables are created automatically
    QFETCH(QString, scene_from);
    QFETCH(QString, scene_to);
    QFETCH(BasicScene::SceneType, scene_from_index);
    uint scene_leave=static_cast<uint>(scene_from_index);
    // Performing the test
    QCOMPARE(SCENE[scene_leave],scene_from);
    QVERIFY2(scene_from != scene_to, "Wrong switch");
}


void gameViewTest::switch_scene_data()
{
    QTest::addColumn<QString>("scene_from");
    QTest::addColumn<QString>("scene_to");
    QTest::addColumn<BasicScene::SceneType>("scene_from_index");

    //    // Generating test cases for the test matrix
    QTest::newRow("city to tampere")      << "city"  << "tampere" << BasicScene::SceneType::City;
    QTest::newRow("univercity to end")      << "university"  << "end" << BasicScene::SceneType::University;
    QTest::newRow("univercity to tampere")      << "university"  << "tampere" << BasicScene::SceneType::University;
    QTest::newRow("univercity to airpots")      << "university"  << "airpots" << BasicScene::SceneType::University;
    QTest::newRow("tampere to city")      << "tampere"  << "city" << BasicScene::SceneType::Tampere;
    QTest::newRow("start to airpots")      << "start"  << "airpots" << BasicScene::SceneType::Start;
    QTest::newRow("airpots to city")      << "airpots"  << "city" << BasicScene::SceneType::Airport;
    QTest::newRow("city to tampere")      << "city"  << "tampere" << BasicScene::SceneType::City;
}

//QTEST_APPLESS_MAIN(gameViewTest)

int main(int argc, char *argv[])
{
   int status = 0;
   {
       gameViewTest ta;
       status |= QTest::qExec(&ta, argc, argv);
   }

   {
       gameViewTest_none tb;
       status |= QTest::qExec(&tb, argc, argv);
   }

   return status;
}

#include "tst_gameviewtest.moc"
