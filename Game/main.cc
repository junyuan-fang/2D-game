#include <QApplication>
//#include "../../Course/CourseLib/graphics/simplemainwindow.hh"
#include "login.hh"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Q_INIT_RESOURCE(offlinedata);
    //CourseSide::SimpleMainWindow w;
    //w.show();

    Login logWindow;
    logWindow.show();
    return a.exec();
}
