#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // == WINDOW SETTINGS ==
        setWindowTitle("QT Przykladowa Aplikacja");
        setMinimumSize(800, 450);

        // --- Pasek Menu
        QMenuBar * menuBar = new QMenuBar(this);
        setMenuBar(menuBar);

        // -- File menu --
        QMenu * menu = menuBar->addMenu("&Przyklady");

        // New
        QAction * action = new QAction("&Przyklad zapytania", this);
        connect(action, &QAction::triggered, this, &MainWindow::OnFileNew);
        menu->addAction(action);

        // Open
        action = new QAction("&Open", this);
        connect(action, &QAction::triggered, this, &MainWindow::OnFileOpen);
        menu->addAction(action);

        // Save
        action = new QAction("&Save", this);
        connect(action, &QAction::triggered, this, &MainWindow::OnFileSave);
        menu->addAction(action);

        // separator
        menu->addSeparator();

        // Exit
        action = new QAction("&Exit", this);
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
void MainWindow::OnFileNew()
{
    //statusBar()->showMessage("Przyklady -> New");
    QMessageBox msgBox;
    msgBox.setText("To jest przyklad zapytania.");
    msgBox.setInformativeText("Mozliwe odpowiedzi na zapytanie typu ,,zapisac''?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

}

void MainWindow::OnFileOpen()
{
    statusBar()->showMessage("Przyklady -> Open");
}

void MainWindow::OnFileSave()
{
    statusBar()->showMessage("Przyklady -> Save");
}
