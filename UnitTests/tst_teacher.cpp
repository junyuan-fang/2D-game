#include <QtTest>

// add necessary includes here

class teacher : public QObject
{
    Q_OBJECT

public:
    teacher();
    ~teacher();

private slots:
    void test_case1();

};

teacher::teacher()
{

}

teacher::~teacher()
{

}

void teacher::test_case1()
{

}

QTEST_APPLESS_MAIN(teacher)

#include "tst_teacher.moc"
