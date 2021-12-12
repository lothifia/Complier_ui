/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *text1;
    QPushButton *pa1;
    QTextEdit *text1_out;
    QListWidget *list1_pcd;
    QListWidget *list1_stk;
    QPushButton *p_ostep;
    QPushButton *p_start;
    QTextEdit *text1_bug;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1157, 724);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        text1 = new QTextEdit(centralwidget);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(70, 90, 281, 581));
        pa1 = new QPushButton(centralwidget);
        pa1->setObjectName(QString::fromUtf8("pa1"));
        pa1->setGeometry(QRect(400, 90, 75, 23));
        text1_out = new QTextEdit(centralwidget);
        text1_out->setObjectName(QString::fromUtf8("text1_out"));
        text1_out->setGeometry(QRect(370, 120, 241, 131));
        list1_pcd = new QListWidget(centralwidget);
        list1_pcd->setObjectName(QString::fromUtf8("list1_pcd"));
        list1_pcd->setGeometry(QRect(370, 260, 241, 411));
        list1_stk = new QListWidget(centralwidget);
        list1_stk->setObjectName(QString::fromUtf8("list1_stk"));
        list1_stk->setGeometry(QRect(620, 10, 241, 661));
        p_ostep = new QPushButton(centralwidget);
        p_ostep->setObjectName(QString::fromUtf8("p_ostep"));
        p_ostep->setGeometry(QRect(490, 90, 75, 23));
        p_start = new QPushButton(centralwidget);
        p_start->setObjectName(QString::fromUtf8("p_start"));
        p_start->setGeometry(QRect(490, 40, 75, 23));
        text1_bug = new QTextEdit(centralwidget);
        text1_bug->setObjectName(QString::fromUtf8("text1_bug"));
        text1_bug->setGeometry(QRect(860, 10, 221, 661));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1157, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        text1->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">main{</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">write 123;</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">}</p></body></html>", nullptr));
        pa1->setText(QCoreApplication::translate("MainWindow", "pa", nullptr));
        p_ostep->setText(QCoreApplication::translate("MainWindow", "one step", nullptr));
        p_start->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        text1_bug->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
