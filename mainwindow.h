#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void komunikatOPrzeniesieniu();
private slots:
    void OnPrzyklad1();
    void OnPrzyklad2();
    void OnDummy();
    void OnComboBoxFrm();
    void OnPrzykladWyjatki();
    void OnPrzykladBazaDanych();
    void OnPrzykladWskazniki();
    void OnEdycjaPol();
};

#endif // MAINWINDOW_H
