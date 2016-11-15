#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/rand.h>
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
    ui->detailsBox->append("Encrypting your message using the public key to generate cipher text.");
    ui->detailsBox->append("Encryption process:");
    ui->detailsBox->append("C = E(PBLK, P)");
    ui->detailsBox->append("C = Cipher Text, E = Encryption method, PBLK = receiver's Public Key and P = Plain Text");
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

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QTextEdit *ourText = ui->textEdit;

    bool generatorHolder = generator::generate_key();
    std::string fileName = "";

    size_t pri_len;             // Length of private key
    size_t pub_len;             // Length of public key
    char *pri_key;              // Private Key
    char *pub_key;              // Public Key
    char msg[KEY_LENGTH/8];	// Message to encrypt
    char *encrypt = NULL;		// Encrypted message
    char *decrypt = NULL;		// Decrypted message
    char *err = NULL;			// Buffer for any error messages
    char name[256];
    char rand_buff[16];
    char *private_key = NULL;	// Private key
    char *public_key = NULL;    // Public key

    memcpy(msg, text.toStdString().c_str(), text.size());
    msg[strlen(msg)] = '\0';

    OpenSSL_add_all_algorithms();

    // Generate Key Pai
    RSA *keypair = RSA_generate_key(KEY_LENGTH, PUB_EXP, NULL, NULL);

    // Get the c-string PEM from:
    BIO *pri = BIO_new(BIO_s_mem());
    BIO *pub = BIO_new(BIO_s_mem());

    // extracting the Public/Private Key into a BIO variable called pub/pri
    PEM_write_bio_RSAPrivateKey(pri, keypair, NULL, NULL, 0, NULL, NULL);
    PEM_write_bio_RSAPublicKey(pub, keypair);

    pri_len = BIO_pending(pri);
    pub_len = BIO_pending(pub);

    pri_key = (char *)malloc(pri_len + 1);
    pub_key = (char *)malloc(pub_len + 1);

    BIO_read(pri, pri_key, pri_len);
    BIO_read(pub, pub_key, pub_len);

    pri_key[pri_len] = '\0';
    pub_key[pub_len] = '\0';

    savePrivateKey(pri_key);
    savePublicKey(pub_key);

    ui->detailsBox->append("*** Starting Encryption of Text ***");
    delay(3);

    ui->detailsBox->append("Setting up encryption...");
    delay(3);
    encrypt = (char *)malloc(RSA_size(keypair));
    int encrypt_len;
    err = (char*)malloc(130);

    ui->detailsBox->append("Executing encryption...");
    delay(3);
    if ((encrypt_len = RSA_public_encrypt(strlen(msg) + 1, (unsigned char*)msg, (unsigned char*)encrypt, keypair, RSA_PKCS1_OAEP_PADDING)) == -1)
    {
          ERR_load_crypto_strings();
          ERR_error_string(ERR_get_error(), err);
          fprintf(stderr, "Error encrypting message: %s\n", err);

    }

    ui->detailsBox->append("Encryption Process finished!");
    delay(1);
    ui->detailsBox->append("*** Printing out Encrypted Message ***");
    delay(1);
    ui->detailsBox->append(encrypt);
    ui->textEdit->setText(encrypt);

    // Write encrypted text to file named encrypted.txt
    QString filename = "encrypted.txt";
    QFile file(filename);
    if(file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << encrypt;
    }

    // Decrypt the message
    decrypt = (char *)malloc(encrypt_len);
    if (RSA_private_decrypt(encrypt_len, (unsigned char*)encrypt, (unsigned char*)decrypt,
        keypair, RSA_PKCS1_OAEP_PADDING) == -1) {
        ERR_load_crypto_strings();
        ERR_error_string(ERR_get_error(), err);
        fprintf(stderr, "Error decrypting message: %s\n", err);
    }

    ui->detailsBox->append("\nPrinting out Decrypted Message:\n");
    delay(2);
    ui->detailsBox->append(decrypt);
    ui->detailsBox->append("\n");


}
