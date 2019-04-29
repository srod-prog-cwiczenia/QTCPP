#include "comboboxfrm.h"
#include <QMessageBox>
#include <sstream>
#include <string>
#include "przyklady.h"

using namespace std;

ComboBoxFrm::ComboBoxFrm(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Formatka z combo box TODO: w przygotowaniu");
    setFixedSize(500, 300);
    btn1 = new QPushButton("Wybór przykładu", this);
    btn1->setGeometry(10, 60, 280, 30);
    btn1->setToolTip("Wybór zaznaczonej opcji");
    QFont font ("Courier");
    btn1->setFont(font);

/*    QGroupBox *echoGroup = new QGroupBox(tr("Echo"));
    QLabel *echoLabel = new QLabel(tr("Mode:")); */
    echoComboBox = new QComboBox(this);
    echoComboBox->setGeometry(10, 10, 280, 30);
    echoComboBox->addItem(tr("Przykłady wskaźników"));
    echoComboBox->addItem(tr("Przykłady przeciążania operatorów"));
    echoComboBox->addItem(tr("Kopiowanie char*"));
    echoComboBox->addItem(tr("Na razie opcja nieużywana 1"));
    echoComboBox->addItem(tr("Na razie opcja nieużywana 2"));

    connect(btn1, SIGNAL (clicked()), this, SLOT (zlapBtn1()));
}
//-------------------------------------------
void ComboBoxFrm::zlapBtn1() {
  QMessageBox msgBox;
  int ind = echoComboBox->currentIndex();
  switch (ind) {
    case 0:
      Przyklady::wskazniki();
      break;
    case 1:
      Przyklady::przeciazanieOperatorow();
      break;
    case 2:
      Przyklady::kopiowanieCharGwiazdka();
      break;
    default: {
        std::ostringstream strs;
        strs << ind;
        string txtIndex = strs.str();
        msgBox.setText((echoComboBox->currentText().toStdString() + " numer opcji: " + txtIndex).c_str());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
  }
}

