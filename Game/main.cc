#include <QApplication>
//#include "../../Course/CourseLib/graphics/simplemainwindow.hh"
#include "login.hh"
#include "cityscene.hh"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Q_INIT_RESOURCE(offlinedata);
    //CourseSide::SimpleMainWindow w;
    //w.show();

    //Login logWindow;
    //logWindow.show();
    //cityScene cityWindow;

    cityScene* scene = new cityScene;

    QGraphicsView view(scene);
    view.show();

    return a.exec();
}
