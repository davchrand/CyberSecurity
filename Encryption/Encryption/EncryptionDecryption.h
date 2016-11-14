#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EncryptionDecryption.h"

class EncryptionDecryption : public QMainWindow
{
    Q_OBJECT

public:
    EncryptionDecryption(QWidget *parent = Q_NULLPTR);

private:
    Ui::EncryptionDecryptionClass ui;
};
