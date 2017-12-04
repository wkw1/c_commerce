/********************************************************************************
** Form generated from reading UI file 'UserView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERVIEW_H
#define UI_USERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserView
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *commodity;
    QWidget *shoppingcart;
    QWidget *bindCard;
    QWidget *myinfo;
    QLabel *userLable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserView)
    {
        if (UserView->objectName().isEmpty())
            UserView->setObjectName(QStringLiteral("UserView"));
        UserView->setEnabled(true);
        UserView->resize(1400, 800);
        centralwidget = new QWidget(UserView);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 70, 891, 551));
        commodity = new QWidget();
        commodity->setObjectName(QStringLiteral("commodity"));
        tabWidget->addTab(commodity, QString());
        shoppingcart = new QWidget();
        shoppingcart->setObjectName(QStringLiteral("shoppingcart"));
        tabWidget->addTab(shoppingcart, QString());
        bindCard = new QWidget();
        bindCard->setObjectName(QStringLiteral("bindCard"));
        tabWidget->addTab(bindCard, QString());
        myinfo = new QWidget();
        myinfo->setObjectName(QStringLiteral("myinfo"));
        tabWidget->addTab(myinfo, QString());
        userLable = new QLabel(centralwidget);
        userLable->setObjectName(QStringLiteral("user"));
        userLable->setGeometry(QRect(20, 10, 151, 31));
        userLable->setTextFormat(Qt::PlainText);
        UserView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserView);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1201, 26));
        UserView->setMenuBar(menubar);
        statusbar = new QStatusBar(UserView);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UserView->setStatusBar(statusbar);

        retranslateUi(UserView);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserView);
    } // setupUi

    void retranslateUi(QMainWindow *UserView)
    {
        UserView->setWindowTitle(QApplication::translate("UserView", "MainWindow", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QApplication::translate("UserView", "<html><head/><body><p>\350\264\255\347\211\251\350\275\246</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        tabWidget->setTabText(tabWidget->indexOf(commodity), QApplication::translate("UserView", "\345\225\206\345\223\201\345\210\227\350\241\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(shoppingcart), QApplication::translate("UserView", "\350\264\255\347\211\251\350\275\246", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(bindCard), QApplication::translate("UserView", "\346\210\221\347\232\204\344\277\241\346\201\257", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        myinfo->setWhatsThis(QApplication::translate("UserView", "<html><head/><body><p>\351\241\265\351\235\242</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        tabWidget->setTabText(tabWidget->indexOf(myinfo), QApplication::translate("UserView", "Tab 2", Q_NULLPTR));
        userLable->setText(QApplication::translate("UserView", "user", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserView: public Ui_UserView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERVIEW_H
