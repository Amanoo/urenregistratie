#include "MainWindow.hpp"
#include "TelepuntSpecificatieModel.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->telepuntSpecView->setModel(new TelepuntSpecificatieModel{});
}

MainWindow::~MainWindow()
{
    delete ui;
}

