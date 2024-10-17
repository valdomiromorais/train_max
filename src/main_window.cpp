//Qt includes
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QMenuBar>
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
    actHlpAbout = new QAction(tr("About"));
    actHlpAbout->setIcon(QIcon("://images/about.png"));
    connect(actHlpAbout, &QAction::triggered, this, &MainWindow::actHlpAboutTriggered);

    actRcdClients = new QAction(tr("Clients"));
    actRcdClients->setIcon(QIcon("://images/client.png"));
    connect(actRcdClients, &QAction::triggered, this, &MainWindow::actRcdClientsTriggered);
}

void MainWindow::createMenus(){
    mnuRecords = new QMenu(tr("Records"));
    mnuRecords->addAction(actRcdClients);

    mnuHelp = new QMenu(tr("Help"));
    mnuHelp->addAction(actHlpAbout);

    menuBar()->addMenu(mnuRecords);
    menuBar()->addMenu(mnuHelp);


}

void MainWindow::createToolBar(){
    tbrRecordsTools = new QToolBar(tr("RecordsTools"));
    tbrRecordsTools->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
    tbrRecordsTools->addAction(actRcdClients);
    addToolBar(tbrRecordsTools);
}

void MainWindow::createStatusBar(){

}

/*Slots*/
void MainWindow::actHlpAboutTriggered(){
    QMessageBox::about(this, tr("About TrainMax"), \
                        tr("<p>Texto do About!</p> Lembrar de colocar as atribuições"));
}

void MainWindow::actRcdClientsTriggered(){
    QMessageBox::warning(this,"Warning", "Em construção!");
}
