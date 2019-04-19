#ifndef DANEOSOBY_H
#define DANEOSOBY_H

#include <QWidget>
#include <QPushButton>

class DaneOsoby : public QWidget
{
    Q_OBJECT
public:
    explicit DaneOsoby(QWidget *parent = 0);
private:
    QPushButton *btn1;
signals:

public slots:
};

#endif // DANEOSOBY_H
