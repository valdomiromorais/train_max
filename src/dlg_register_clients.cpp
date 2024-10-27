#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QFrame>
#include <QTabWidget>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include "include/dlg_register_clients.h"

DlgRegisterClients::DlgRegisterClients(QWidget *parent):QDialog(parent){
    setupUi();
    setWindowFlags(Qt::Dialog);
    setWindowTitle(tr("Registering Clients"));
}

void DlgRegisterClients::setupUi(){

    /*Line Edits*/
    ledName        = new QLineEdit(this);
    ledCPF         = new QLineEdit(this);
    ledCPF->setInputMask("000.000.000.000");
    ledRG          = new QLineEdit(this);
    ledFone        = new QLineEdit(this);
    ledSocialMidia = new QLineEdit(this);
    ledPerfil      = new QLineEdit(this);

    /*Buttons*/
    pbtRegister = new QPushButton(tr("&Register"),this);
    pbtCancel   = new QPushButton(tr("&Cancel"),this);

    /*Others*/
    dedBirthDay = new QDateEdit(this);

    /*Labels*/
    lblName        = new QLabel(tr("&Name:"),this);
    lblName->setBuddy(ledName);
    lblCPF         = new QLabel(tr("CP&F: "),this);
    lblCPF->setBuddy(ledCPF);
    lblRG          = new QLabel(tr("R&G: "),this);
    lblRG->setBuddy(ledRG);
    lblBirthDay    = new QLabel(tr("&Birth Day: "),this);
    lblBirthDay->setBuddy(dedBirthDay);
    lblFone        = new QLabel(tr("F&one: "),this);
    lblFone->setBuddy(ledFone);
    lblSocialMidia = new QLabel(tr("&Social Midia: "),this);
    lblSocialMidia->setBuddy(ledSocialMidia);
    lblPerfil      = new QLabel(tr("&Perfil"),this);
    lblPerfil->setBuddy(ledPerfil);

    /*Frames*/
    frmPersonalData = new QFrame(this);
    frmPersonalData->setFrameShape(QFrame::Panel);
    frmAddress      = new QFrame(this);
    frmAddress->setFrameShape(QFrame::Panel);
    frmButtons      = new QFrame(this);
    frmButtons->setFrameShape(QFrame::Panel);

    twgClientData   = new QTabWidget(this);

    /*Layouts*/
    QGridLayout *lytPersonalData = new QGridLayout(frmPersonalData);
    lytPersonalData->addWidget(lblName,0,0);
    lytPersonalData->addWidget(ledName,0,1,1,3);

    lytPersonalData->addWidget(lblCPF,1,0);
    lytPersonalData->addWidget(ledCPF,1,1);
    lytPersonalData->addWidget(lblRG,1,2);
    lytPersonalData->addWidget(ledRG,1,3);

    lytPersonalData->addWidget(lblBirthDay,2,0);
    lytPersonalData->addWidget(dedBirthDay,2,1);
    lytPersonalData->addWidget(lblFone,2,2);
    lytPersonalData->addWidget(ledFone,2,3);

    lytPersonalData->addWidget(lblSocialMidia,3,0);
    lytPersonalData->addWidget(ledSocialMidia,3,1);
    lytPersonalData->addWidget(lblPerfil,3,2);
    lytPersonalData->addWidget(ledPerfil,3,3);

    /* TODO: Create the address widgets
     * QGridLayout *lytAddress = new QGridLayout(frmAddress);
     * lytAddress->addWidget(nullptr);*/

    QHBoxLayout *lytButtons = new QHBoxLayout(frmButtons);
    lytButtons->addStretch();
    lytButtons->addWidget(pbtRegister);
    lytButtons->addWidget(pbtCancel);

    twgClientData->addTab(frmPersonalData,tr("Personal &Data"));
    twgClientData->addTab(frmAddress,tr("&Address"));

    QVBoxLayout *lytGeral = new QVBoxLayout(this);
    lytGeral->addWidget(twgClientData);
    lytGeral->addWidget(frmButtons);

    setLayout(lytGeral);

}
