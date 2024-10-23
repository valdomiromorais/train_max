//Qt includes
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QMenuBar>
#include <QLayout>
#include <QLabel>
#include <QMessageBox>
//My includes
#include "include/main_window.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    setupUi();


    setWindowIcon(QIcon("://images/gym_main.png"));
    setWindowTitle(tr("TrainMax - Gym Management System"));
    setWindowState(Qt::WindowMaximized);
}

/*AUX. FUNCTIONS*/
void MainWindow::setupUi(){
    createActions();
    createMenus();
    createToolBar();
    createStatusBar();
}//setupUi

void MainWindow::createActions(){

    /*Records (Rcd) Actions*/
    actRcdClients = new QAction(tr("Clients"));
    actRcdClients->setIcon(QIcon("://images/client.png"));
    actRcdClients->setToolTip(tr("Client registration"));
    actRcdClients->setShortcut(QKeySequence("Ctrl+N"));
    actRcdClients->setStatusTip(tr("Registration of new clients for your gym."));
    connect(actRcdClients, &QAction::triggered, this, &MainWindow::actRcdClientsTriggered);

    actRcdTrainer = new QAction(tr("Trainer"));
    actRcdTrainer->setIcon(QIcon("://images/trainer.png"));
    actRcdTrainer->setToolTip(tr("Trainer registration"));
    actRcdTrainer->setShortcut(QKeySequence("Ctrl+T"));
    actRcdTrainer->setStatusTip(tr("Registration of new trainer for your gym."));
    connect(actRcdTrainer, &QAction::triggered, this, &MainWindow::actRcdTrainerTriggered);

    actRcdProfiles = new QAction(tr("Profiles"));
    actRcdProfiles->setIcon(QIcon("://images/profiles.png"));
    actRcdProfiles->setToolTip(tr("Client profiles registration"));
    //actRcdProfiles->setShortcut(QKeySequence("Ctrl+P"));
    actRcdProfiles->setStatusTip(tr("Registration of new clients profiles for your gym."));
    connect(actRcdProfiles, &QAction::triggered, this, &MainWindow::actRcdProfilesTriggered);

    /*CashFlow (Csf) Actions*/
    actCsfReceipts = new QAction(tr("Receipts"));
    actCsfReceipts->setIcon(QIcon("://images/receipt.png"));
    actCsfReceipts->setToolTip(tr("Receipts registration"));
    actCsfReceipts->setShortcut(QKeySequence("Ctrl+R"));
    actCsfReceipts->setStatusTip(tr("Registration of new receipt."));
    connect(actCsfReceipts, &QAction::triggered, this, &MainWindow::actCsfReceiptsTriggered);

    actCsfPayment = new QAction(tr("Payment"));
    actCsfPayment->setIcon(QIcon("://images/payment.png"));
    actCsfPayment->setToolTip(tr("Payment registration"));
    actCsfPayment->setShortcut(QKeySequence("Ctrl+P"));
    actCsfPayment->setStatusTip(tr("Registration of new payments."));
    connect(actCsfPayment, &QAction::triggered, this, &MainWindow::actCsfPaymentTriggered);

    actCsfTypes = new QAction(tr("Cash Flow Types"));
    actCsfTypes->setIcon(QIcon("://images/cash_flow_types.png"));
    actCsfTypes->setToolTip(tr("Cash flow types registration"));
    //actCsfTypes->setShortcut(QKeySequence("Ctrl+F"));
    actCsfTypes->setStatusTip(tr("Registration of new cash flow types."));
    connect(actCsfTypes, &QAction::triggered, this, &MainWindow::actCsfTypesTriggered);

    /*Shop (Shp) Actions*/
    actShpSale = new QAction(tr("Shop Sale"));
    actShpSale->setIcon(QIcon("://images/sale.png"));
    actShpSale->setToolTip(tr("Make a sale for your store"));
    //actShpSale->setShortcut(QKeySequence("Ctrl+F"));
    actShpSale->setStatusTip(tr("Make a direct sale to your customer in your store"));
    connect(actShpSale, &QAction::triggered, this, &MainWindow::actShpSaleTriggered);

    actShpProducts = new QAction(tr("Shop Products"));
    actShpProducts->setIcon(QIcon("://images/products.png"));
    actShpProducts->setToolTip(tr("Registering new products."));
    //actShpProducts->setShortcut(QKeySequence("Ctrl+F"));
    actShpProducts->setStatusTip(tr("Registering new products for your store."));
    connect(actShpProducts, &QAction::triggered, this, &MainWindow::actShpProductsTriggered);

    /*Equipament (Eqp) Actions*/
    actEqpNewEquipment = new QAction(tr("New Equipament"));
    actEqpNewEquipment->setIcon(QIcon("://images/equipaments.png"));
    actEqpNewEquipment->setToolTip(tr("Registering new equipament."));
    //actEqpNewEquipment->setShortcut(QKeySequence("Ctrl+F"));
    actEqpNewEquipment->setStatusTip(tr("Registering new equipament for your gym."));
    connect(actEqpNewEquipment, &QAction::triggered, this, &MainWindow::actEqpNewEquipmentTriggered);

    /*Training (Tng) Actions*/
    actTngAddExercises = new QAction(tr("Add Exercises"));
    actTngAddExercises->setIcon(QIcon("://images/exercises.png"));
    actTngAddExercises->setToolTip(tr("Registering new exercise type."));
    //actTngAddExercises->setShortcut(QKeySequence("Ctrl+F"));
    actTngAddExercises->setStatusTip(tr("Registering new exercise type."));
    connect(actTngAddExercises, &QAction::triggered, this, &MainWindow::actTngAddExercisesTriggered);

    actTngTraining = new QAction(tr("Add Training"));
    actTngTraining->setIcon(QIcon("://images/training.png"));
    actTngTraining->setToolTip(tr("Registering new training."));
    //actTngTraining->setShortcut(QKeySequence("Ctrl+F"));
    actTngTraining->setStatusTip(tr("Registering new exercise type."));
    connect(actTngTraining, &QAction::triggered, this, &MainWindow::actTngTrainingTriggered);

    /*System (Sys) Actions*/
    actSysUsers = new QAction(tr("Users"));
    actSysUsers->setIcon(QIcon("://images/user.png"));
    actSysUsers->setToolTip(tr("System user registration"));
    //actSysUsers->setShortcut(QKeySequence("Ctrl+U"));
    actSysUsers->setStatusTip(tr("Registration of new user for this system."));
    connect(actSysUsers, &QAction::triggered, this, &MainWindow::actSysUsersTriggered);

    actSysPreferences = new QAction(tr("Preferences"));
    actSysPreferences->setIcon(QIcon("://images/preferences.png"));
    actSysPreferences->setToolTip(tr("System preferences config"));
    //actSysPreferences->setShortcut(QKeySequence("Ctrl+P"));
    actSysPreferences->setStatusTip(tr("System preferences configurations."));
    connect(actSysPreferences, &QAction::triggered, this, &::MainWindow::actSysPreferencesTriggered);

    /*Work Schedule*/
    actWksSchedule = new QAction(tr("Schedule"));
    actWksSchedule->setIcon(QIcon("://images/schedule.png"));
    actWksSchedule->setToolTip(tr("Gym Schedule"));
    //actWksSchedule->setShortcut(QKeySequence("Ctrl+P"));
    actWksSchedule->setStatusTip(tr("Gym Schedule for treiners and athletics"));
    connect(actWksSchedule, &QAction::triggered, this, &MainWindow::actWksScheduleTriggered);

    actWksCalendar = new QAction(tr("Calendar"));
    actWksCalendar->setIcon(QIcon("://images/calendar.png"));
    actWksCalendar->setToolTip(tr("Gym Calendar"));
    //actWksCalendar->setShortcut(QKeySequence("Ctrl+P"));
    actWksCalendar->setStatusTip(tr("Gym Calendar for treiners and athletics"));
    connect(actWksCalendar, &QAction::triggered, this, &MainWindow::actWksCalendarTriggered);

    /*Help Actions*/
    actHlpAbout = new QAction(tr("About"));
    actHlpAbout->setIcon(QIcon("://images/about.png"));
    actHlpAbout->setToolTip(tr("Information about TrainMax"));
    actHlpAbout->setStatusTip(tr("Application information and acknowledgements"));
    connect(actHlpAbout, &QAction::triggered, this, &MainWindow::actHlpAboutTriggered);

    actHlpDocumentation = new QAction(tr("Documentation"));
    actHlpDocumentation->setIcon(QIcon("://images/documentation.png"));
    actHlpDocumentation->setToolTip(tr("The documentation of the TrainMax"));
    actHlpDocumentation->setStatusTip(tr("The documentation step-by-step of the application use."));
    connect(actHlpDocumentation, &QAction::triggered, this, &MainWindow::actHlpDocumentationTriggered);
}

void MainWindow::createMenus(){
    mnuRecords = new QMenu(tr("Records"));
    mnuRecords->addAction(actRcdClients);
    mnuRecords->addAction(actRcdTrainer);
    mnuRecords->addAction(actRcdProfiles);

    mnuCashFlow = new QMenu(tr("Cash Flow"));
    mnuCashFlow->addAction(actCsfReceipts);
    mnuCashFlow->addAction(actCsfPayment);
    mnuCashFlow->addAction(actCsfTypes);

    mnuWorkSchedule = new QMenu(tr("Work Schedule"));
    mnuWorkSchedule->addAction(actWksSchedule);
    mnuWorkSchedule->addAction(actWksCalendar);

    mnuTraining = new QMenu(tr("Training"));
    mnuTraining->addAction(actTngAddExercises);
    mnuTraining->addAction(actTngTraining);

    mnuShop = new QMenu(tr("Shop"));
    mnuShop->addAction(actShpProducts);
    mnuShop->addAction(actShpSale);

    mnuEquipment = new QMenu(tr("Equipment"));
    mnuEquipment->addAction(actEqpNewEquipment);
    //mnuEquipment->addAction(actEqp);

    mnuReports = new QMenu(tr("Reports"));

    mnuTurnstile = new QMenu(tr("Turnstile"));

    mnuSystem = new QMenu(tr("System"));
    mnuSystem->addAction(actSysUsers);
    mnuSystem->addAction(actSysPreferences);

    mnuHelp = new QMenu(tr("Help"));
    mnuHelp->addAction(actHlpAbout);
    mnuHelp->addAction(actHlpDocumentation);

    menuBar()->addMenu(mnuRecords);
    menuBar()->addMenu(mnuCashFlow);
    menuBar()->addMenu(mnuWorkSchedule);
    menuBar()->addMenu(mnuShop);
    menuBar()->addMenu(mnuEquipment);
    menuBar()->addMenu(mnuTraining);
    menuBar()->addMenu(mnuReports);
    menuBar()->addMenu(mnuTurnstile);
    menuBar()->addMenu(mnuSystem);
    menuBar()->addMenu(mnuHelp);


}

void MainWindow::createToolBar(){
    tbrRecordsTools = new QToolBar(tr("RecordsTools"));
    tbrRecordsTools->setIconSize(QSize(45,45));
    tbrRecordsTools->setAllowedAreas(Qt:: LeftToolBarArea | Qt::TopToolBarArea | Qt::BottomToolBarArea );
    //tbrRecordsTools->
    tbrRecordsTools->setStyleSheet("QToolButton {background-color: gray; width: 50px; height: 50px;}");
    //----- Add Actions
    tbrRecordsTools->addAction(actRcdClients);
    tbrRecordsTools->addAction(actRcdTrainer);
    tbrRecordsTools->addSeparator();
    tbrRecordsTools->addAction(actCsfReceipts);
    tbrRecordsTools->addSeparator();
    tbrRecordsTools->addAction(actWksSchedule);
    tbrRecordsTools->addAction(actWksCalendar);
    tbrRecordsTools->addSeparator();
    tbrRecordsTools->addAction(actShpSale);
    tbrRecordsTools->addSeparator();
    tbrRecordsTools->addAction(actTngTraining);


    QWidget *spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    tbrRecordsTools->addWidget(spacer);
    tbrRecordsTools->addSeparator();
    tbrRecordsTools->addAction(actHlpDocumentation);


    addToolBar(tbrRecordsTools);
}

void MainWindow::createStatusBar(){
    statusBar()->addWidget(new QLabel(tr("Não esqueça a status bar!!!")));
}

/*SLOTS*/
//Rcd
void MainWindow::actRcdTrainerTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actRcdProfilesTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actRcdClientsTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

//Csf
void MainWindow::actCsfReceiptsTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actCsfPaymentTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actCsfTypesTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

//Shp
void MainWindow::actShpProductsTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

//Tng
void MainWindow::actTngAddExercisesTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actTngTrainingTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actShpSaleTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

//Eqp
void MainWindow::actEqpNewEquipmentTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

//Wks
void MainWindow::actWksScheduleTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actWksCalendarTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

//Sys
void MainWindow::actSysUsersTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actSysPreferencesTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

//Hlp
void MainWindow::actHlpAboutTriggered(){
    QMessageBox::about(this, tr("About TrainMax"), \
                        tr("<p>Esta aplicação tem por objetivo educacional <br> \
                            a formação dos alunos do IF Sertão em programação de computadores</p> \
                            Acknowledgements:<br>\
                            Icons designed by various authors from Flaticon<br>\
                            <a href='https://www.flaticon.com/free-icons/gym'>www.flaticon.com</a>"));
}

void MainWindow::actHlpDocumentationTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}
