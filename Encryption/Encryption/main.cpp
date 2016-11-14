#include "EncryptionDecryption.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EncryptionDecryption w;
    w.show();
    return a.exec();
}
