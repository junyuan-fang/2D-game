#include <QtTest>
#include <QString>
#include <QVector>
#include <QVector2D>
#include "../../Game/map/airportmap.hh"
#include "../../Game/map/citymap.hh"
#include "../../Game/map/hospitalmap.hh"
#include "../../Game/map/universitymap.hh"
// add necessary includes here


//airpot
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
    AirportMap airport;
    int x=0;
    int y=0;
    if(object_name=="Player_start"){
        QVector2D  coordinate  = airport.getPlayerStartPosition();
         x= coordinate [0];
         y= coordinate [1];
    }
    else if(object_name=="Player_end"){
        QVector2D  coordinate  = airport.getPlayerEndPosition();
        x= coordinate [0];
        y= coordinate [1];
    }
    else if(object_name=="Enemy"){
       QVector<QVector2D>  coordinates  = airport.getEnemyPosition();
         for (auto coordinate: coordinates ){
              x= coordinate [0];
              y= coordinate [1];
             QVERIFY2( x<=5120 && x>=0,"Object's x-coordinate value is out of the range" );
             QVERIFY2( y<=5120 && y>=0,"Object's y-coordinate value is out of the range" );
         }
        return ;
    }
    else if(object_name=="tutor"){
        QVector2D  coordinate  = airport.getGraphicsItemPosition(object_name.toStdString());
         x= coordinate [0];
         y= coordinate [1];
    }
    else if(object_name=="erp"){
        QVector2D  coordinate  = airport.getGraphicsItemPosition(object_name.toStdString());
         x= coordinate [0];
         y= coordinate [1];
    }
    else if(object_name=="airCrew"){
        QVector2D  coordinate  = airport.getGraphicsItemPosition(object_name.toStdString());
         x= coordinate [0];
         y= coordinate [1];
    }

    else{
        QVERIFY2( 1==0,"Object's position not found " );
    }


    //map size is 5120x675
    QVERIFY2( x<=5120 && x>=0,"Object's x-coordinate value is out of the range" );
    QVERIFY2( y<=5120 && y>=0,"Object's y-coordinate value is out of the range" );
}

void AirportMapTest::object_in_map_data()
{
    QTest::addColumn<QString>("object_name");
    QTest::addColumn<int >("x");
    QTest::addColumn<int>("y");
    //    // Generating test cases for the test matrix
    QTest::newRow("PlayerStartPosition")   << "Player_start"   ;
    QTest::newRow("Enemy")      << "Enemy"   ;
    QTest::newRow("Tutor")      << "tutor"   ;
    QTest::newRow("Erp")      << "erp"   ;
    QTest::newRow("AirCrew")      << "airCrew"   ;
    QTest::newRow("PlayerEndPosition")      << "Player_end"  ;
}


//citymap, quite same like airportmap's
class CitytMapTest : public QObject
{
    Q_OBJECT

public:
    CitytMapTest();
    ~CitytMapTest();

private slots:
    void object_in_map();
    void object_in_map_data();
};

CitytMapTest::CitytMapTest()
{
}

CitytMapTest::~CitytMapTest()
{
}

void CitytMapTest::object_in_map()
{
    QFETCH(QString,object_name);
    CityMap city;
    int x=0;
    int y=0;
    if(object_name=="Player_start"){
        QVector2D  coordinate  = city.getPlayerStartPosition();
         x= coordinate [0];
         y= coordinate [1];
    }
    else if(object_name=="Player_end"){
        QVector2D  coordinate  = city.getPlayerEndPosition();
        x= coordinate [0];
        y= coordinate [1];
    }
    else if(object_name=="Enemy"){
       QVector<QVector2D>  coordinates  = city.getEnemyPosition();
         for (auto coordinate: coordinates ){
              x= coordinate [0];
              y= coordinate [1];
             QVERIFY2( x<=5120 && x>=0,"Object's x-coordinate value is out of the range" );
             QVERIFY2( y<=5120 && y>=0,"Object's y-coordinate value is out of the range" );
         }
        return ;
    }
    else if(object_name=="bank"){
        QVector2D  coordinate  = city.getGraphicsItemPosition(object_name.toStdString());
         x= coordinate [0];
         y= coordinate [1];
    }
    else{
        QVERIFY2( 1==0,"Object's position not found " );
    }

    //map size is 5120x675
    QVERIFY2( x<=5120 && x>=0,"Object's x-coordinate value is out of the range" );
    QVERIFY2( y<=5120 && y>=0,"Object's y-coordinate value is out of the range" );
}

void CitytMapTest::object_in_map_data()
{
    QTest::addColumn<QString>("object_name");
    QTest::addColumn<int >("x");
    QTest::addColumn<int>("y");
    //    // Generating test cases for the test matrix
    QTest::newRow("PlayerStartPosition")   << "Player_start"   ;
    QTest::newRow("Enemy")      << "Enemy"   ;
    QTest::newRow("Bank")      << "bank"   ; ;
    QTest::newRow("PlayerEndPosition")      << "Player_end"  ;
}



//hospital
class HospitalMapTest : public QObject
{
    Q_OBJECT

public:
    HospitalMapTest();
    ~HospitalMapTest();

private slots:
    void object_in_map();
    void object_in_map_data();
};

HospitalMapTest::HospitalMapTest()
{
}

HospitalMapTest::~HospitalMapTest()
{
}

void HospitalMapTest::object_in_map()
{
    QFETCH(QString,object_name);
    HospitalMap hospital;
    int x=0;
    int y=0;
    if(object_name=="Player_start"){
        QVector2D  coordinate  = hospital.getPlayerStartPosition();
         x= coordinate [0];
         y= coordinate [1];
    }
    else if(object_name=="Player_end"){
        QVector2D  coordinate  = hospital.getPlayerEndPosition();
        x= coordinate [0];
        y= coordinate [1];
    }
    else if(object_name=="Enemy"){
       QVector<QVector2D>  coordinates  = hospital.getEnemyPosition();
         for (auto coordinate: coordinates ){
              x= coordinate [0];
              y= coordinate [1];
             QVERIFY2( x<=5120 && x>=0,"Object's x-coordinate value is out of the range" );
             QVERIFY2( y<=5120 && y>=0,"Object's y-coordinate value is out of the range" );
         }
        return ;
    }
    else if(object_name=="tutor"){
        QVector2D  coordinate  = hospital.getGraphicsItemPosition(object_name.toStdString());
         x= coordinate [0];
         y= coordinate [1];
    }
    else if(object_name=="gate"){
        QVector2D  coordinate  = hospital.getGraphicsItemPosition(object_name.toStdString());
         x= coordinate [0];
         y= coordinate [1];
    }

    else{
        QVERIFY2( 1==0,"Object's position not found " );
    }


    //map size is 5120x675
    QVERIFY2( x<=5120 && x>=0,"Object's x-coordinate value is out of the range" );
    QVERIFY2( y<=5120 && y>=0,"Object's y-coordinate value is out of the range" );
}

void HospitalMapTest::object_in_map_data()
{
    QTest::addColumn<QString>("object_name");
    QTest::addColumn<int >("x");
    QTest::addColumn<int>("y");
    //    // Generating test cases for the test matrix
    QTest::newRow("PlayerStartPosition")   << "Player_start"   ;
    QTest::newRow("Enemy")      << "Enemy"   ;
    QTest::newRow("Tutor")      << "tutor"   ;
    QTest::newRow("Gate")      << "gate"   ;
    QTest::newRow("PlayerEndPosition")      << "Player_end"  ;
}




//universuty
class UniversityMapTest : public QObject
{
    Q_OBJECT

public:
    UniversityMapTest();
    ~UniversityMapTest();

private slots:
    void object_in_map();
    void object_in_map_data();
};

UniversityMapTest::UniversityMapTest()
{
}

UniversityMapTest::~UniversityMapTest()
{
}

void UniversityMapTest::object_in_map()
{
    QFETCH(QString,object_name);
    UniversityMap airport;
    int x=0;
    int y=0;
    if(object_name=="Player_start"){
        QVector2D  coordinate  = airport.getPlayerStartPosition();
         x= coordinate [0];
         y= coordinate [1];
    }
    else if(object_name=="Player_end"){
        QVector2D  coordinate  = airport.getPlayerEndPosition();
        x= coordinate [0];
        y= coordinate [1];
    }
    else if(object_name=="Enemy"){
       QVector<QVector2D>  coordinates  = airport.getEnemyPosition();
         for (auto coordinate: coordinates ){
              x= coordinate [0];
              y= coordinate [1];
             QVERIFY2( x<=5120 && x>=0,"Object's x-coordinate value is out of the range" );
             QVERIFY2( y<=5120 && y>=0,"Object's y-coordinate value is out of the range" );
         }
        return ;
    }
    else if(object_name=="cleaner"){
        QVector2D  coordinate  = airport.getGraphicsItemPosition(object_name.toStdString());
         x= coordinate [0];
         y= coordinate [1];
    }
    else if(object_name=="teacher"){
        QVector2D  coordinate  = airport.getGraphicsItemPosition(object_name.toStdString());
         x= coordinate [0];
         y= coordinate [1];
    }

    else{
        QVERIFY2( 1==0,"Object's position not found " );
    }


    //map size is 5120x675
    QVERIFY2( x<=5120 && x>=0,"Object's x-coordinate value is out of the range" );
    QVERIFY2( y<=5120 && y>=0,"Object's y-coordinate value is out of the range" );
}

void UniversityMapTest::object_in_map_data()
{
    QTest::addColumn<QString>("object_name");
    QTest::addColumn<int >("x");
    QTest::addColumn<int>("y");
    //    // Generating test cases for the test matrix
    QTest::newRow("PlayerStartPosition")   << "Player_start"   ;
    QTest::newRow("Enemy")      << "Enemy"   ;
    QTest::newRow("Cleaner")      << "cleaner"   ;
    QTest::newRow("Teacher")      << "teacher"   ;
    QTest::newRow("PlayerEndPosition")      << "Player_end"  ;
}

int main(int argc, char *argv[])
{
    int status = 0;

    {
        AirportMapTest ta;
         status |= QTest::qExec(&ta, argc, argv);
    }

    {
        CitytMapTest tb;
        status |= QTest::qExec(&tb, argc, argv);
    }

    {
        HospitalMapTest tb;
        status |= QTest::qExec(&tb, argc, argv);
    }

    {
        UniversityMapTest tb;
        status |= QTest::qExec(&tb, argc, argv);
    }

   return status;
}

#include "tst_maptest.moc"
