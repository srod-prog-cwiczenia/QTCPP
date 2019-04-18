#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication aplikacja(argc, argv);
    MainWindow okno;
    okno.show();
    return aplikacja.exec();
}
