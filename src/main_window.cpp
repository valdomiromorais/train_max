//Qt includes
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QMenuBar>
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

/*Aux. Functions*/
void MainWindow::setupUi(){
    //TODO: implementar a interface básica do sistema de gerenciamento
    createActions();
    createMenus();
    createToolBar();
    createStatusBar();
}//setupUi

void MainWindow::createActions(){
    /*Help Actions*/
    actHlpAbout = new QAction(tr("About"));
    actHlpAbout->setIcon(QIcon("://images/about.png"));
    actHlpAbout->setToolTip(tr("Information about TrainMax"));
    actHlpAbout->setStatusTip(tr("Application information and acknowledgements"));
    connect(actHlpAbout, &QAction::triggered, this, &MainWindow::actHlpAboutTriggered);

    /*Records Actions*/
    actRcdClients = new QAction(tr("Clients"));
    actRcdClients->setIcon(QIcon("://images/client.png"));
    actRcdClients->setToolTip(tr("Client registration"));
    actRcdClients->setShortcut(QKeySequence("Ctrl+N"));
    actRcdClients->setStatusTip(tr("Registration of new clients for your gym."));
    connect(actRcdClients, &QAction::triggered, this, &MainWindow::actRcdClientsTriggered);

    actRcdProfiles = new QAction(tr("Profiles"));
    actRcdProfiles->setIcon(QIcon("://images/profiles.png"));
    actRcdProfiles->setToolTip(tr("Client profiles registration"));
    actRcdProfiles->setShortcut(QKeySequence("Ctrl+P"));
    actRcdProfiles->setStatusTip(tr("Registration of new clients profiles for your gym."));


    /*System Actions*/
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
}

void MainWindow::createMenus(){
    mnuRecords = new QMenu(tr("Records"));
    mnuRecords->addAction(actRcdClients);
    mnuRecords->addAction(actRcdProfiles);

    mnuCashFlow = new QMenu(tr("Cash Flow"));

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
    //tbrRecordsTools->set
    tbrRecordsTools->setIconSize(QSize(45,45));
    tbrRecordsTools->setAllowedAreas(Qt:: LeftToolBarArea | Qt::TopToolBarArea | Qt::BottomToolBarArea );
    tbrRecordsTools->addAction(actRcdClients);
    tbrRecordsTools->setStyleSheet("QToolButton {background-color: gray; width: 50px; height: 50px;}");

    addToolBar(tbrRecordsTools);
}

void MainWindow::createStatusBar(){
    statusBar()->addWidget(new QLabel(tr("Não esqueça a status bar!!!")));
}

/*Slots*/

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
    //
}

void MainWindow::actSysPreferencesTriggered(){}
