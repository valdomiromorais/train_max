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

QAction* MainWindow::createAction(QString name, QString icon_path, QString tool_tip, QString short_cut, QString status_tip){
    QAction *an_action = new QAction(name,this);
    an_action->setIcon(QIcon(icon_path));
    an_action->setToolTip(tool_tip);
    an_action->setShortcut(QKeySequence(short_cut));
    an_action->setStatusTip(status_tip);

    return an_action;
}

void MainWindow::createActions(){

    actRcdClients = createAction( tr("Clients"),"://images/client.png",
                                    tr("Client registration"),"Ctrl+N",
                                    "Registration of new clients for your gym.");
    connect(actRcdClients, &QAction::triggered, this, &MainWindow::actRcdClientsTriggered);

    actRcdTrainer = createAction( tr("Trainer"),"://images/trainer.png",
                                    tr("Trainer registration"),"Ctrl+T",
                                    "Registration of new trainer for your gym.");
     connect(actRcdTrainer, &QAction::triggered, this, &MainWindow::actRcdTrainerTriggered);

     actRcdProfiles = createAction( tr("Profiles"),"://images/profiles.png",
                                      tr("Client profiles registration"),"Ctrl+P",
                                      "Registration of new clients profiles for your gym.");
     connect(actRcdProfiles, &QAction::triggered, this, &MainWindow::actRcdProfilesTriggered);

     /*CashFlow (Csf) Actions*/
    actCsfReceipts = createAction( tr("Receipts"),"://images/receipt.png",
                                     tr("Receipts registration"),"Ctrl+R",
                                     "Registration of new receipt.");
    connect(actCsfReceipts, &QAction::triggered, this, &MainWindow::actCsfReceiptsTriggered);

    actCsfPayment = createAction( tr("Payment"),"://images/payment.png",
                                    tr("Payment registration"),"Ctrl+P",
                                    "Registration of new payments.");
    connect(actCsfPayment, &QAction::triggered, this, &MainWindow::actCsfPaymentTriggered);


    actCsfTypes = createAction( tr("Cash Flow Types"),"://images/cash_flow_types.png",
                                   tr("Cash flow types registration"),"Ctrl+F",
                                   "Registration of new cash flow types.");
    connect(actCsfTypes, &QAction::triggered, this, &MainWindow::actCsfTypesTriggered);

    /*Shop (Shp) Actions*/

    actShpSale = createAction( tr("Shop Sale"),"://images/sale.png",
                                 tr("Make a sale for your store"),"Ctrl+G",
                                 "Make a direct sale to your customer in your store");
    connect(actShpSale, &QAction::triggered, this, &MainWindow::actShpSaleTriggered);

    actShpProducts = createAction( tr("Shop Products"),"://images/products.png",
                                     tr("Registering new products."),"Ctrl+B",
                                     "Registering new products for your store.");
    connect(actShpProducts, &QAction::triggered, this, &MainWindow::actShpProductsTriggered);

    /*Equipament (Eqp) Actions*/

    actEqpNewEquipment = createAction( tr("New Equipament"),"://images/equipaments.png",
                                         tr("Registering new equipament."),"Ctrl+E",
                                         "Registering new equipament for your gym.");
    connect(actEqpNewEquipment, &QAction::triggered, this, &MainWindow::actEqpNewEquipmentTriggered);

    /*Training (Tng) Actions*/

    actTngAddExercises = createAction( tr("Add Exercises"),"://images/exercises.png",
                                         tr("Registering new exercise type."),"Ctrl+",
                                         "Registering new exercise type.");
    connect(actTngAddExercises, &QAction::triggered, this, &MainWindow::actTngAddExercisesTriggered);

    actTngTraining = createAction( tr("Add Training"),"://images/training.png",
                                         tr("Registering new training."),"Ctrl+",
                                         "Registering new exercise type.");
    connect(actTngTraining, &QAction::triggered, this, &MainWindow::actTngTrainingTriggered);

    /*System (Sys) Actions*/

    actSysUsers = createAction( tr("Users"),"://images/user.png",
                                  tr("System user registration"),"Ctrl+",
                                  "Registration of new user for this system.");
    connect(actSysUsers, &QAction::triggered, this, &MainWindow::actSysUsersTriggered);


    actSysPreferences = createAction( tr("Preferences"),"://images/preferences.png",
                                        tr("System preferences config"),"Ctrl+",
                                        "System preferences configurations.");
    connect(actSysPreferences, &QAction::triggered, this, &::MainWindow::actSysPreferencesTriggered);

    /*Work Schedule*/

    actWksSchedule = createAction( tr("Schedule"),"://images/schedule.png",
                     tr("Gym Schedule"),"Ctrl+",
                     "Gym Schedule for treiners and athletics");
    connect(actWksSchedule, &QAction::triggered, this, &MainWindow::actWksScheduleTriggered);


    actWksCalendar = createAction( tr("Calendar"),"://images/calendar.png",
                     tr("Gym Calendar"),"Ctrl+",
                     "Gym Calendar for treiners and athletics");
    connect(actWksCalendar, &QAction::triggered, this, &MainWindow::actWksCalendarTriggered);

    /*Help Actions*/

    actHlpAbout = createAction( tr("About"),"://images/about.png",
                     tr("Information about TrainMax"),"Ctrl+",
                     "Application information and acknowledgements");
    connect(actHlpAbout, &QAction::triggered, this, &MainWindow::actHlpAboutTriggered);

    actHlpDocumentation = createAction( tr("Documentation"),"://images/documentation.png",
                                  tr("The documentation of the TrainMax"),"Ctrl+",
                                  "The documentation step-by-step of the application use.");
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
    QMessageBox::warning(this,"Warning", "Registro de Treinador em construção!");
}

void MainWindow::actRcdProfilesTriggered(){
    QMessageBox::warning(this,"Warning", "Registro de Profiles em construção!");
}

void MainWindow::actRcdClientsTriggered(){
    QMessageBox::warning(this,"Warning", "Registro de Clientes em construção!");
}

//Csf
void MainWindow::actCsfReceiptsTriggered(){
    QMessageBox::warning(this,"Warning", "Recebimentos em construção!");
}

void MainWindow::actCsfPaymentTriggered(){
    QMessageBox::warning(this,"Warning", "Pagamentos em construção!");
}

void MainWindow::actCsfTypesTriggered(){
    QMessageBox::warning(this,"Warning", "Tipos em fluxo de caixa em construção!");
}

//Shp
void MainWindow::actShpProductsTriggered(){
    QMessageBox::warning(this,"Warning", "Produtos em construção!");
}

//Tng
void MainWindow::actTngAddExercisesTriggered(){
    QMessageBox::warning(this,"Warning", "Exercícios em construção!");
}

void MainWindow::actTngTrainingTriggered(){
    QMessageBox::warning(this,"Warning", "Treinamento em construção!");
}

void MainWindow::actShpSaleTriggered(){
    QMessageBox::warning(this,"Warning", "Vendas em construção!");
}

//Eqp
void MainWindow::actEqpNewEquipmentTriggered(){
    QMessageBox::warning(this,"Warning", "Novo equipamento em construção!");
}

//Wks
void MainWindow::actWksScheduleTriggered(){
    QMessageBox::warning(this,"Warning", "Escala em construção!");
}

void MainWindow::actWksCalendarTriggered(){
    QMessageBox::warning(this,"Warning", "Calendário em construção!");
}

//Sys
void MainWindow::actSysUsersTriggered(){
    QMessageBox::warning(this,"Warning", "Usuários em construção!");
}

void MainWindow::actSysPreferencesTriggered(){
    QMessageBox::warning(this,"Warning", "Preferencias em construção!");
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
    QMessageBox::warning(this,"Warning", "Documentação em construção!");
}
