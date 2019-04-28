#include "comboboxfrm.h"
#include <QMessageBox>
#include <sstream>
#include <string>
using namespace std;

ComboBoxFrm::ComboBoxFrm(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Formatka z combo box TODO: w przygotowaniu");
    setFixedSize(500, 300);
    btn1 = new QPushButton("Na razie przycisk nieaktywny", this);
    btn1->setGeometry(10, 60, 280, 30);
    btn1->setToolTip("TODO: utworzyc combo box");
    QFont font ("Courier");
    btn1->setFont(font);

/*    QGroupBox *echoGroup = new QGroupBox(tr("Echo"));
    QLabel *echoLabel = new QLabel(tr("Mode:")); */
    echoComboBox = new QComboBox(this);
    echoComboBox->setGeometry(10, 10, 280, 30);
    echoComboBox->addItem(tr("Opcja 1"));
    echoComboBox->addItem(tr("Opcja 2"));
    echoComboBox->addItem(tr("Opcja 3"));
    echoComboBox->addItem(tr("Opcja 4"));

    connect(btn1, SIGNAL (clicked()), this, SLOT (zlapBtn1()));
}
//-------------------------------------------
void ComboBoxFrm::zlapBtn1() {
  QMessageBox msgBox;
  int ind = echoComboBox->currentIndex();
  std::ostringstream strs;
  strs << ind;
  string txtIndex = strs.str();
  msgBox.setText((echoComboBox->currentText().toStdString() + " numer opcji: " + txtIndex).c_str());
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.setDefaultButton(QMessageBox::Ok);
  msgBox.exec();
}

