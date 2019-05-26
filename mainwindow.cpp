#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopWidget>
//#include <QWidget> - zapewne w MainWindow zbedne
#include "przyklady.h"
#include "bazydanych.h"
#include "daneosoby.h"
#include "comboboxfrm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
// ustawienia okna
    /*QDesktopWidget dw;
    int x=dw.width() * 0.8;
    int y=dw.height() * 0.8;*/ //jeden ze sposobow odczytania rozmiaru calego desktopwidgeta

    // get the dimension available on this screen
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width() * 0.95;
    int height = availableSize.height() * 0.95;

    setFixedSize(width, height);
    setWindowTitle("QT Przykladowa Aplikacja");

   //   setMinimumSize(800, 450);
    // --- Pasek Menu
    QMenuBar * menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // -- Menu Przyklady --
    QMenu * menu = menuBar->addMenu("&Przyklady");

    // New
    QAction * action = new QAction("&Przyklad zapytania", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnPrzyklad1);
    menu->addAction(action);

    // Przyklad przeciazania operatorow
    action = new QAction("&Przyklad przeciazania operatorow", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnPrzyklad2);
    menu->addAction(action);

    // Edycja pol
    action = new QAction("&Edycja pol", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnEdycjaPol);
    menu->addAction(action);

    // Dummy (do pozniejszego uzycia)
    action = new QAction("&Menu combo box", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnComboBoxFrm);
    menu->addAction(action);

    // Dummy (do pozniejszego uzycia)
    action = new QAction("&Dummy", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnDummy);
    menu->addAction(action);

    // separator
    menu->addSeparator();

    // Wyjście
    action = new QAction("&Koniec", this);
    connect(action, &QAction::triggered, this, &MainWindow::close);
    menu->addAction(action);

    // == STATUS BAR ==
    QStatusBar * statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    // druga czesc menu:
    QMenu * przyklady2 = menuBar->addMenu("&Przyklady 2");
    // Przyklad do wyjątków
    action = new QAction("&Wyjątki", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnPrzykladWyjatki);
    przyklady2->addAction(action);

    // Przyklad do bazy danych
    action = new QAction("&Baza danych", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnPrzykladBazaDanych);
    przyklady2->addAction(action);

    // Wskaźniki (przykłady):
    action = new QAction("&Wskazniki", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnPrzykladWskazniki);
    przyklady2->addAction(action);

}

void MainWindow::komunikatOPrzeniesieniu() {
    QMessageBox msgBox;
    msgBox.setText("Przeniesione do menu combo box");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//----- prywatne sloty ---------
void MainWindow::OnPrzyklad1()
{
    //statusBar()->showMessage("Przyklady -> Zapytanie");
    QMessageBox msgBox;
    msgBox.setText("To jest przyklad zapytania.");
    msgBox.setInformativeText("Mozliwe odpowiedzi na zapytanie typu ,,zapisac''?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    /*int ret = */msgBox.exec();
    // ujęcie int ret tylko celem wytępienia warninga o nieużywanej zmiennej ret
}

void MainWindow::OnPrzyklad2()
{
    komunikatOPrzeniesieniu();
    //Przyklady::przeciazanieOperatorow();
}

void MainWindow::OnDummy()
{
    statusBar()->showMessage("Przyklady -> Dummy ");
}
void MainWindow::OnComboBoxFrm() {
    statusBar()->showMessage("Okno z combobox");
    ComboBoxFrm *frm = new ComboBoxFrm;
    frm->showNormal();
}
void MainWindow::OnPrzykladWyjatki() {
    statusBar()->showMessage("Do oprogramowania!");
    Przyklady::wyjatki();
}
void MainWindow::OnPrzykladBazaDanych() {
    statusBar()->showMessage("Baza danych - przyklad");
    bazyDanych::przyklad1();
}
void MainWindow::OnEdycjaPol() {
    statusBar()->showMessage("Do utworzenia nowe okno");
    DaneOsoby *daneOso = new DaneOsoby;
    daneOso->showNormal();
    /*TODO: tak można rzekomo ustawić modalność okna ALE w tym kontekście nie działa (dlaczego?) */
    //daneOso->setWindowModality(Qt::WindowModal);

}
void MainWindow::OnPrzykladWskazniki() {
    statusBar()->showMessage("Wskazniki - przyklad");
    komunikatOPrzeniesieniu();
    //Przyklady::wskazniki();
}
