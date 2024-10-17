#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class QMenu;
class QAction;
class QToolBar;
class QStatusBar;

/**
 * This class represents the main window of the application.
 * @author Valdomiro Morais <valdomiromorais@gmail.com>
 * @since 0.1
 */
class MainWindow: public QMainWindow{
    Q_OBJECT

    public:
        MainWindow(QWidget* parent = nullptr);
    private slots:
        /*Action Slots*/
        void actHlpAboutTriggered();
        void actRcdClientsTriggered();
    private:
        /*Auxiliary function used to configure the UI*/
        void setupUi();
        void createActions();
        void createMenus();
        void createToolBar();
        void createStatusBar();



        /*Actions*/
        QAction *actHlpAbout;
        QAction *actRcdClients;

        /*Menus*/
        QMenu *mnuHelp;   //Hlp
        QMenu *mnuRecords;//Rcd

        /*ToolsBar*/
        QToolBar *tbrRecordsTools;


};//end class

#endif // MAIN_WINDOW_H
