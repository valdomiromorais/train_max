#include <QApplication>
//#include <QSqlDatabase>
//#include <QChart>

#include "include/main_window.h"


int main(int argc, char** argv){
    QApplication app(argc, argv);

    MainWindow mw;

    mw.show();

    return app.exec();

}//main
