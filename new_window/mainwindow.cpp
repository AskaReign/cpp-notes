#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gridwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    new_window_btn = new QPushButton("Open Window", this);
    setCentralWidget(new_window_btn);

    connect(new_window_btn, &QPushButton::clicked, this, [this]() {
        auto *gw = new GridWindow();
        gw->show();
    });

    resize(200, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}


