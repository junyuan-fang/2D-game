#include <QtTest>

// add necessary includes here

class MapTest : public QObject
{
    Q_OBJECT

public:
    MapTest();
    ~MapTest();

private slots:
    void test_case1();

};

MapTest::MapTest()
{

}

MapTest::~MapTest()
{

}

void MapTest::test_case1()
{

}

QTEST_APPLESS_MAIN(MapTest)

#include "tst_maptest.moc"
