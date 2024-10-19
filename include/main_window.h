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
        void actSysUsersTriggered();
        void actSysPreferencesTriggered();
    private:
        /*Auxiliary function used to configure the UI*/
        void setupUi();
        void createActions();
        void createMenus();
        void createToolBar();
        void createStatusBar();


        /*ACTIONS*/
        /*Records Actions (Rcd)*/
        QAction *actRcdClients;
        QAction *actRcdProfiles;

        /*System Actions (Sys)*/
        QAction *actSysUsers;
        QAction *actSysPreferences;

        /*Help Actions (Hlp)*/
        QAction *actHlpAbout;


        /*MENUS*/
        QMenu *mnuRecords;      //Rcd
        QMenu *mnuSystem;       //Sys
        QMenu *mnuCashFlow;     //Csf
        QMenu *mnuWorkSchedule; //Wks (Escala)
        QMenu *mnuReports;      //Rpt
        QMenu *mnuTurnstile;    //Trn (Catraca)
        QMenu *mnuHelp;         //Hlp

        /*ToolsBar*/
        QToolBar *tbrRecordsTools;


};//end class

#endif // MAIN_WINDOW_H
