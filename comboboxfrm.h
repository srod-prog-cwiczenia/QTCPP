#ifndef COMBOBOXFRM_H
#define COMBOBOXFRM_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>


class ComboBoxFrm: public QWidget {
    Q_OBJECT
    public:
        explicit ComboBoxFrm(QWidget *parent = 0);
    private:
        QPushButton *btn1;
        QComboBox *echoComboBox;
    signals:

    public slots:
        void zlapBtn1();
};

#endif // COMBOBOXFRM_H
