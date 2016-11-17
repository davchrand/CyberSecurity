/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
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
    QTextEdit *decryptText;
    QPushButton *chooseFile;
    QPushButton *decryptButton;
    QLabel *label_2;
    QTextEdit *detailsBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(751, 761);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 0, 281, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        decryptText = new QTextEdit(centralWidget);
        decryptText->setObjectName(QStringLiteral("decryptText"));
        decryptText->setGeometry(QRect(10, 40, 731, 391));
        chooseFile = new QPushButton(centralWidget);
        chooseFile->setObjectName(QStringLiteral("chooseFile"));
        chooseFile->setGeometry(QRect(410, 0, 141, 31));
        chooseFile->setFont(font);
        decryptButton = new QPushButton(centralWidget);
        decryptButton->setObjectName(QStringLiteral("decryptButton"));
        decryptButton->setGeometry(QRect(10, 440, 731, 31));
        decryptButton->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 480, 61, 21));
        label_2->setFont(font);
        detailsBox = new QTextEdit(centralWidget);
        detailsBox->setObjectName(QStringLiteral("detailsBox"));
        detailsBox->setGeometry(QRect(10, 510, 731, 181));
        QFont font1;
        font1.setPointSize(10);
        detailsBox->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 751, 26));
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
        label->setText(QApplication::translate("MainWindow", "Text to be Decrypted below or", 0));
        chooseFile->setText(QApplication::translate("MainWindow", "Text from File", 0));
        decryptButton->setText(QApplication::translate("MainWindow", "Decrypt", 0));
        label_2->setText(QApplication::translate("MainWindow", "Details:", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
