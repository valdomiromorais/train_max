#include <QApplication>
#include <QFile> //://style.qss

#include "include/main_window.h"
//#include "include/dlg_register_clients.h"

QString set_applacation_style();

int main(int argc, char** argv){
    QApplication app(argc, argv);

    //app.setStyleSheet(set_applacation_style());

    MainWindow mw;

    mw.show();

    return app.exec();

}//main

QString set_applacation_style(){
    //Load the application style
    QFile  styleFile("://style.qss");

    styleFile.open(QFile::ReadOnly);

    //Apply the loaded stylesheet
    QString  style(styleFile.readAll());

    return style;
}
