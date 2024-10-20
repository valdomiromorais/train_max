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

    actCsfPayment = new QAction(tr("Payment"));
    actCsfPayment->setIcon(QIcon("://images/payment.png"));
    actCsfPayment->setToolTip(tr("Payment registration"));
    actCsfPayment->setShortcut(QKeySequence("Ctrl+P"));
    actCsfPayment->setStatusTip(tr("Registration of new payments."));

    actCsfTypes = new QAction(tr("Cash Flow Types"));
    actCsfTypes->setIcon(QIcon("://images/cash_flow_types.png"));
    actCsfTypes->setToolTip(tr("Cash flow types registration"));
    //actCsfTypes->setShortcut(QKeySequence("Ctrl+F"));
    actCsfTypes->setStatusTip(tr("Registration of new cash flow types."));

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

    /*Help Actions*/
    actHlpAbout = new QAction(tr("About"));
    actHlpAbout->setIcon(QIcon("://images/about.png"));
    actHlpAbout->setToolTip(tr("Information about TrainMax"));
    actHlpAbout->setStatusTip(tr("Application information and acknowledgements"));
    connect(actHlpAbout, &QAction::triggered, this, &MainWindow::actHlpAboutTriggered);
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

    mnuReports = new QMenu(tr("Reports"));

    mnuTurnstile = new QMenu(tr("Turnstile"));

    mnuSystem = new QMenu(tr("System"));
    mnuSystem->addAction(actSysUsers);
    mnuSystem->addAction(actSysPreferences);

    mnuHelp = new QMenu(tr("Help"));
    mnuHelp->addAction(actHlpAbout);

    menuBar()->addMenu(mnuRecords);
    menuBar()->addMenu(mnuCashFlow);
    menuBar()->addMenu(mnuWorkSchedule);
    menuBar()->addMenu(mnuReports);
    menuBar()->addMenu(mnuTurnstile);
    menuBar()->addMenu(mnuSystem);
    menuBar()->addMenu(mnuHelp);


}

void MainWindow::createToolBar(){
    tbrRecordsTools = new QToolBar(tr("RecordsTools"));
    tbrRecordsTools->setIconSize(QSize(45,45));
    tbrRecordsTools->setAllowedAreas(Qt:: LeftToolBarArea | Qt::TopToolBarArea | Qt::BottomToolBarArea );
    tbrRecordsTools->setStyleSheet("QToolButton {background-color: gray; width: 50px; height: 50px;}");
    tbrRecordsTools->addAction(actRcdClients);
    tbrRecordsTools->addAction(actRcdTrainer);
    tbrRecordsTools->addSeparator();
    tbrRecordsTools->addAction(actCsfReceipts);

    addToolBar(tbrRecordsTools);
}

void MainWindow::createStatusBar(){
    statusBar()->addWidget(new QLabel(tr("Não esqueça a status bar!!!")));
}

/*SLOTS*/
void MainWindow::actHlpAboutTriggered(){
    QMessageBox::about(this, tr("About TrainMax"), \
                        tr("<p>Esta aplicação tem por objetivo educacional <br> \
                            a formação dos alunos do IF Sertão em programação de computadores</p> \
                            Acknowledgements:<br>\
                            Icons designed by various authors from Flaticon<br>\
                            <a href='https://www.flaticon.com/free-icons/gym'>www.flaticon.com</a>"));
}

void MainWindow::actRcdClientsTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actSysUsersTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actSysPreferencesTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actRcdTrainerTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}

void MainWindow::actRcdProfilesTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}
