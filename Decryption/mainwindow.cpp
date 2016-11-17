#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Qtime>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encryptionGenerator.h"

#define KEY_LENGTH  2048
#define PUB_EXP     3

void delay(int secs)
{
    QTime dieTime= QTime::currentTime().addSecs(secs);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->detailsBox->append("CSCI 4800 Cybersecurity project");
    ui->detailsBox->append("A new pair of public/private keys were generated for you at:");
    ui->detailsBox->append("public.pem and private.pem");
    ui->detailsBox->append("Decrypting your message using private key to decipher text.");
    ui->detailsBox->append("Decryption process:");
    ui->detailsBox->append("P = D(PRVK,E(PBLK,P))");
    ui->detailsBox->append("D = Decryption method, PBLK = receiver's Public Key, PRVK = receiver's Private Key and P = Plain Text");
    ui->detailsBox->append("...\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// generate and save private key at private.pem
void savePrivateKey(char *keypair){
  FILE* pFile;

  if (pFile = fopen("private.pem", "wb"))
  {
    fprintf(pFile, "%s", keypair);
  }
  else{
    printf("PEM_write_PrivateKey failed.\n");
  }

  if (pFile)
  {
    fclose(pFile);
    pFile = NULL;
  }
}
 // generate and save public key at public.pem
void savePublicKey(char *keypair){
  FILE* pFile;

  if (pFile = fopen("public.pem", "wb"))
  {
    fprintf(pFile, "%s", keypair);
  }
  else{
    printf("PEM_write_PublicKey failed.\n");
  }

  if (pFile)
  {
    fclose(pFile);
    pFile = NULL;
  }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_decryptButton_clicked()
{
    QString text = ui->decryptText->toPlainText();
    std::string str = text.toStdString();
    char *encrypted = new char[str.length() + 1];
    strcpy(encrypted, str.c_str());

    char *decrypt = NULL;		// Decrypted message
    char *err = NULL;			// Buffer for any error messages

    OpenSSL_add_all_algorithms();

    QString privateKey = "";
    QString filename = "private.pem";
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        privateKey = stream.readAll();
    }

    std::string key = privateKey.toStdString();
    char *pKey = new char[key.length() + 1];
    strcpy(pKey, key.c_str());

    RSA *priKey = NULL;
    BIO *keybio;
    keybio = BIO_new_mem_buf(pKey, -1);
    if (keybio==NULL)
    {
        printf( "Failed to create key BIO");
        QApplication::quit();
    }
    priKey = PEM_read_bio_RSAPrivateKey(keybio, &priKey,NULL, NULL);
    if(priKey == NULL)
    {
        printf( "Failed to create RSA");
    }

    ui->detailsBox->append("*** Starting Decryption of Text ***");
    delay(2);

    ui->detailsBox->append("Setting up decryption...");
    delay(2);

    ui->detailsBox->append("Executing Decryption...");
    delay(2);

    err = (char*)malloc(130);

    // Decrypt the message
    int encrypt_len = strlen(encrypted);
    decrypt = (char *)malloc(encrypt_len);
    if (RSA_private_decrypt(256, (unsigned char*)encrypted, (unsigned char*)decrypt, priKey, RSA_PKCS1_OAEP_PADDING) == -1) {
        ERR_load_crypto_strings();
        ERR_error_string(ERR_get_error(), err);
        fprintf(stderr, "Error decrypting message: %s\n", err);
    }

    ui->detailsBox->append("Decryption Process finished!");
    delay(1);
    ui->detailsBox->append("*** Printing out Decrypted Message ***\n");
    delay(1);
    QString string(decrypt);
    ui->detailsBox->append(string);

    delete [] encrypted;
    delete [] pKey;
}

void MainWindow::on_chooseFile_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All Files (*.*);;Text File (*.txt)"
                );
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "File Information", file.errorString());

    QTextStream in(&file);

    ui->decryptText->setText(in.readAll());
}
