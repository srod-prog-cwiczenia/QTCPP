#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include "przyklady.h"

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

    // -- File menu --
    QMenu * menu = menuBar->addMenu("&Przyklady");

    // New
    QAction * action = new QAction("&Przyklad zapytania", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnPrzyklad1);
    menu->addAction(action);

    // Open
    action = new QAction("&Przyklad przeciazania operatorow", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnPrzyklad2);
    menu->addAction(action);

    // Save
    action = new QAction("&Dummy", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnPrzyklad3);
    menu->addAction(action);

    // separator
    menu->addSeparator();

    // Exit
    action = new QAction("&Koniec", this);
    connect(action, &QAction::triggered, this, &MainWindow::close);
    menu->addAction(action);

    // == STATUS BAR ==
    QStatusBar * statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//----- prywatne sloty ---------
void MainWindow::OnPrzyklad1()
{
    //statusBar()->showMessage("Przyklady -> New");
    QMessageBox msgBox;
    msgBox.setText("To jest przyklad zapytania.");
    msgBox.setInformativeText("Mozliwe odpowiedzi na zapytanie typu ,,zapisac''?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

}

void MainWindow::OnPrzyklad2()
{
    Przyklady::przeciazanieOperatorow();
}

void MainWindow::OnPrzyklad3()
{
    statusBar()->showMessage("Przyklady -> Dummy ");
}
