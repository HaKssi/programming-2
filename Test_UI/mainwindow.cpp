#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "test_ui_1.h"
#include <qpainter.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //hide();
    //Test_UI_1 test_ui_1;
    QDialog test_ui_1;
    test_ui_1.setModal(true);
    test_ui_1.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    QDialog test_ui_2;
    test_ui_2.setModal(true);
    test_ui_2.exec();
}

