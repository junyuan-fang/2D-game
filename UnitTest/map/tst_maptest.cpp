#include <QtTest>
#include <QString>
#include <QVector2D>
#include "../../Game/map/airportmap.hh"
// add necessary includes here

class AirportMapTest : public QObject
{
    Q_OBJECT

public:
    AirportMapTest();
    ~AirportMapTest();

private slots:
    void object_in_map();
    void object_in_map_data();
};

AirportMapTest::AirportMapTest()
{
}

AirportMapTest::~AirportMapTest()
{
}

void AirportMapTest::object_in_map()
{
    QFETCH(QString,object_name);
    QFETCH(int,x);
    QFETCH(int,y);

}

void AirportMapTest::object_in_map_data()
{

}

QTEST_APPLESS_MAIN(AirportMapTest)

#include "tst_maptest.moc"
