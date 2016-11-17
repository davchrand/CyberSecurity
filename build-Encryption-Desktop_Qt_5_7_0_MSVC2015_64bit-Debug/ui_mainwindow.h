/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QLabel *label;
    QTextEdit *encryptText;
    QPushButton *pushButton;
    QLabel *label_2;
    QTextEdit *detailsBox;
    QPushButton *fileDialog;
    QPushButton *generateKeys;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 829);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 0, 281, 31));
        label->setFont(font);
        encryptText = new QTextEdit(centralWidget);
        encryptText->setObjectName(QStringLiteral("encryptText"));
        encryptText->setGeometry(QRect(10, 40, 681, 411));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 460, 681, 31));
        pushButton->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 500, 71, 20));
        label_2->setFont(font);
        detailsBox = new QTextEdit(centralWidget);
        detailsBox->setObjectName(QStringLiteral("detailsBox"));
        detailsBox->setGeometry(QRect(10, 520, 681, 221));
        QFont font1;
        font1.setPointSize(10);
        detailsBox->setFont(font1);
        fileDialog = new QPushButton(centralWidget);
        fileDialog->setObjectName(QStringLiteral("fileDialog"));
        fileDialog->setGeometry(QRect(440, 0, 141, 31));
        fileDialog->setFont(font);
        generateKeys = new QPushButton(centralWidget);
        generateKeys->setObjectName(QStringLiteral("generateKeys"));
        generateKeys->setGeometry(QRect(10, 0, 141, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 34));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        label->setText(QApplication::translate("MainWindow", "Text to be encrypted below or", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Encrypt", 0));
        label_2->setText(QApplication::translate("MainWindow", "Details:", 0));
        fileDialog->setText(QApplication::translate("MainWindow", "Choose File", 0));
        generateKeys->setText(QApplication::translate("MainWindow", "Generate Keys", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
