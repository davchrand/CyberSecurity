/********************************************************************************
** Form generated from reading UI file 'EncryptionDecryption.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCRYPTIONDECRYPTION_H
#define UI_ENCRYPTIONDECRYPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EncryptionDecryptionClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EncryptionDecryptionClass)
    {
        if (EncryptionDecryptionClass->objectName().isEmpty())
            EncryptionDecryptionClass->setObjectName(QStringLiteral("EncryptionDecryptionClass"));
        EncryptionDecryptionClass->resize(600, 400);
        menuBar = new QMenuBar(EncryptionDecryptionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        EncryptionDecryptionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EncryptionDecryptionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EncryptionDecryptionClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(EncryptionDecryptionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        EncryptionDecryptionClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(EncryptionDecryptionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EncryptionDecryptionClass->setStatusBar(statusBar);

        retranslateUi(EncryptionDecryptionClass);

        QMetaObject::connectSlotsByName(EncryptionDecryptionClass);
    } // setupUi

    void retranslateUi(QMainWindow *EncryptionDecryptionClass)
    {
        EncryptionDecryptionClass->setWindowTitle(QApplication::translate("EncryptionDecryptionClass", "EncryptionDecryption", 0));
    } // retranslateUi

};

namespace Ui {
    class EncryptionDecryptionClass: public Ui_EncryptionDecryptionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCRYPTIONDECRYPTION_H
