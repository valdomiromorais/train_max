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
        void actRcdTrainerTriggered();
        void actRcdProfilesTriggered();
    private:
        /*Auxiliary function used to configure the UI*/
        void setupUi();
        void createActions();
        void createMenus();
        void createToolBar();
        void createStatusBar();


        /*ACTIONS*/
        /*Records (Rcd) Actions*/
        QAction *actRcdClients;
        QAction *actRcdProfiles;
        QAction *actRcdTrainer;

        /*CashFlow (Csf) Actions*/
        QAction *actCsfReceipts; //(pt_br: Recebimentos)
        QAction *actCsfPayment;  //(pt_br: Pagamentos)
        QAction *actCsfTypes;    //

        /*System (Sys) Actions*/
        QAction *actSysUsers;
        QAction *actSysPreferences;

        /*Help (Hlp) Actions*/
        QAction *actHlpAbout;


        /*MENUS*/
        QMenu *mnuRecords;      //Rcd
        QMenu *mnuCashFlow;     //Csf
        QMenu *mnuWorkSchedule; //Wks (pt_br: Escala)
        QMenu *mnuReports;      //Rpt
        QMenu *mnuTurnstile;    //Trn (pt_br: Catraca)
        QMenu *mnuSystem;       //Sys
        QMenu *mnuHelp;         //Hlp

        /*ToolsBar*/
        QToolBar *tbrRecordsTools;


};//end class

#endif // MAIN_WINDOW_H
