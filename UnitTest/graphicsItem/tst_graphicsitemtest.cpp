#include <QtTest>

// add necessary includes here

class GraphicsItemTest : public QObject
{
    Q_OBJECT

public:
    GraphicsItemTest();
    ~GraphicsItemTest();

private slots:
    void test_case1();

};

GraphicsItemTest::GraphicsItemTest()
{

}

GraphicsItemTest::~GraphicsItemTest()
{

}

void GraphicsItemTest::test_case1()
{

}

QTEST_APPLESS_MAIN(GraphicsItemTest)

#include "tst_graphicsitemtest.moc"
