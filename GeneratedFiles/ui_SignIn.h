/********************************************************************************
** Form generated from reading UI file 'SignIn.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignInWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userID;
    QLineEdit *password;
    QPushButton *signIn;
    QPushButton *register_2;
    QLabel *info;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SignInWindow)
    {
        if (SignInWindow->objectName().isEmpty())
            SignInWindow->setObjectName(QStringLiteral("SignInWindow"));
        SignInWindow->resize(800, 600);
        centralwidget = new QWidget(SignInWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 250, 72, 15));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 210, 72, 15));
        userID = new QLineEdit(centralwidget);
        userID->setObjectName(QStringLiteral("userID"));
        userID->setGeometry(QRect(230, 210, 141, 21));
        password = new QLineEdit(centralwidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(230, 250, 141, 21));
        password->setEchoMode(QLineEdit::Password);
        signIn = new QPushButton(centralwidget);
        signIn->setObjectName(QStringLiteral("signIn"));
        signIn->setGeometry(QRect(210, 320, 93, 28));
        register_2 = new QPushButton(centralwidget);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(210, 390, 93, 28));
        info = new QLabel(centralwidget);
        info->setObjectName(QStringLiteral("info"));
        info->setGeometry(QRect(140, 470, 341, 21));
        SignInWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SignInWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        SignInWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SignInWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SignInWindow->setStatusBar(statusbar);

        retranslateUi(SignInWindow);

        QMetaObject::connectSlotsByName(SignInWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SignInWindow)
    {
        SignInWindow->setWindowTitle(QApplication::translate("SignInWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("SignInWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("SignInWindow", "ID", Q_NULLPTR));
        signIn->setText(QApplication::translate("SignInWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        register_2->setText(QApplication::translate("SignInWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        info->setText(QApplication::translate("SignInWindow", "11", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignInWindow: public Ui_SignInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
