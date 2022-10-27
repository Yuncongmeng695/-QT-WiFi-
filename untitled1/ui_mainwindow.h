/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_go;
    QPushButton *pushButton_right;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_back;
    QPushButton *pushButton_left;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_connect;
    QComboBox *cbb_speed;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(825, 706);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_go = new QPushButton(centralWidget);
        pushButton_go->setObjectName(QString::fromUtf8("pushButton_go"));
        pushButton_go->setGeometry(QRect(120, 160, 90, 90));
        pushButton_right = new QPushButton(centralWidget);
        pushButton_right->setObjectName(QString::fromUtf8("pushButton_right"));
        pushButton_right->setGeometry(QRect(220, 260, 90, 90));
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(120, 260, 90, 90));
        pushButton_back = new QPushButton(centralWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(120, 360, 90, 90));
        pushButton_left = new QPushButton(centralWidget);
        pushButton_left->setObjectName(QString::fromUtf8("pushButton_left"));
        pushButton_left->setGeometry(QRect(20, 260, 90, 90));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 70, 111, 51));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(320, 160, 231, 291));
        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(120, 50, 111, 41));
        cbb_speed = new QComboBox(centralWidget);
        cbb_speed->setObjectName(QString::fromUtf8("cbb_speed"));
        cbb_speed->setGeometry(QRect(600, 160, 91, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 825, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_go->setText(QCoreApplication::translate("MainWindow", "\345\211\215", nullptr));
        pushButton_right->setText(QCoreApplication::translate("MainWindow", "\345\217\263", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234", nullptr));
        pushButton_back->setText(QCoreApplication::translate("MainWindow", "\345\220\216", nullptr));
        pushButton_left->setText(QCoreApplication::translate("MainWindow", "\345\267\246", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\252\350\277\236\346\216\245\345\260\217\350\275\246", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
