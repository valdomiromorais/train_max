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
        //Rcd
        void actRcdClientsTriggered();
        void actRcdTrainerTriggered();
        void actRcdProfilesTriggered();
        //Csf
        void actCsfReceiptsTriggered();
        void actCsfPaymentTriggered();
        void actCsfTypesTriggered();
        //Wls
        void actWksScheduleTriggered();
        void actWksCalendarTriggered();
        //Shp
        void actShpProductsTriggered();
        void actShpSaleTriggered();
        //Tng
        void actTngAddExercisesTriggered();
        void actTngTrainingTriggered();
        //Eqp
        void actEqpNewEquipmentTriggered();
        //Sys
        void actSysUsersTriggered();
        void actSysPreferencesTriggered();
        //Hlp
        void actHlpAboutTriggered();
        void actHlpDocumentationTriggered();
    private:
        /*Auxiliary function used to configure the UI*/
        void setupUi();
        void createActions();
        void createMenus();
        void createToolBar();
        void createStatusBar();

        QAction* createAction( QString name="", QString icon_path = "",
                             QString tool_tip = "", QString short_cut="",
                             QString status_tip="");

        /*ACTIONS*/

        /*Records (Rcd) Actions*/
        QAction *actRcdClients;
        QAction *actRcdProfiles;
        QAction *actRcdTrainer;

        /*CashFlow (Csf) Actions*/
        QAction *actCsfReceipts; //(pt_br: Recebimentos)
        QAction *actCsfPayment;  //(pt_br: Pagamentos)
        QAction *actCsfTypes;    //

        /*Training (Tng) Actions*/
        QAction *actTngAddExercises; //
        QAction *actTngTraining;     //

        /*WorkSchedule (Wks) Actions*/
        QAction *actWksSchedule; //(pt_br: Agenda)
        QAction *actWksCalendar; //(pt_br: Calendário)

        /*Shop (Shp) Actions*/
        QAction *actShpProducts;
        QAction *actShpSale;
        QAction *actShp;
        //QAction *actShp;

        /*Equipament (Eqp) Actions*/
        QAction *actEqpNewEquipment; //

        /*System (Sys) Actions*/
        QAction *actSysUsers;
        QAction *actSysPreferences;

        /*Help (Hlp) Actions*/
        QAction *actHlpAbout;
        QAction *actHlpDocumentation;


        /*MENUS*/
        QMenu *mnuRecords;      //Rcd
        QMenu *mnuCashFlow;     //Csf
        QMenu *mnuWorkSchedule; //Wks (pt_br: Escala)
        QMenu *mnuReports;      //Rpt
        QMenu *mnuTurnstile;    //Trn (pt_br: Catraca)
        QMenu *mnuShop;         //Shp
        QMenu *mnuEquipment;    //Eqp (pt_br: Equipamento)
        QMenu *mnuTraining;     //Tng
        QMenu *mnuSystem;       //Sys
        QMenu *mnuHelp;         //Hlp

        /*ToolsBar*/
        QToolBar *tbrRecordsTools;


};//end class

#endif // MAIN_WINDOW_H
