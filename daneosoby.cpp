#include "daneosoby.h"
#include <QMessageBox>

DaneOsoby::DaneOsoby(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Edycja danych osoby TODO: w przygotowaniu");
    setFixedSize(500, 300);
    btn1 = new QPushButton("Na razie przycisk nieaktywny", this);
    btn1->setGeometry(10, 10, 280, 30);
    btn1->setToolTip("TODO: utworzyc edycje danych osoby");
    QFont font ("Courier");
    btn1->setFont(font);

    /*QGroupBox *echoGroup = new QGroupBox(tr("Echo"));
    QLabel *echoLabel = new QLabel(tr("Mode:"));
    QComboBox *echoComboBox = new QComboBox;
    echoComboBox->addItem(tr("Normal"));
    echoComboBox->addItem(tr("Password"));
    echoComboBox->addItem(tr("PasswordEchoOnEdit"));
    echoComboBox->addItem(tr("No Echo"));*/
}

