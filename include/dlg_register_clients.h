#ifndef DLG_REGISTER_CLIENTS_H
#define DLG_REGISTER_CLIENTS_H
#include <QDialog>

class QTabWidget;
class QLabel;
class QLineEdit;
class QDateEdit;
class QFrame;

class DlgRegisterClients: public QDialog{
    Q_OBJECT
    public:
        explicit DlgRegisterClients(QWidget *parent = nullptr);
    private slots:

    private:
        void setupUi();

        /*Labels*/
        QLabel *lblName;
        QLabel *lblCPF;
        QLabel *lblRG;
        QLabel *lblBirthDay;
        QLabel *lblFone;
        QLabel *lblSocialMidia;
        QLabel *lblPerfil;

        /*Line Edits*/
        QLineEdit *ledName;
        QLineEdit *ledCPF;
        QLineEdit *ledRG;
        QLineEdit *ledFone;
        QLineEdit *ledSocialMidia;
        QLineEdit *ledPerfil;

        /*Buttons*/
        QPushButton* pbtRegister;
        QPushButton* pbtCancel;

        /*Others*/
        QDateEdit *dedBirthDay;

        /*Frames*/
        QFrame *frmPersonalData;
        QFrame *frmAddress;
        QFrame *frmButtons;

        QTabWidget *twgClientData;
};

#endif // DLG_REGISTER_CLIENTS_H
