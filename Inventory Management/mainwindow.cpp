#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_item_clicked()
{
    addi = new Add_item(this);
    addi->show();
}

void MainWindow::on_Edit_item_clicked()
{
    editi = new Edit_item(this);
    editi->exec();

}

void MainWindow::on_del_clicked()
{
    deletei = new Delete_item(this);
    deletei->exec();
}

void MainWindow::on_In_clicked()
{
    ini = new In(this);
    ini->exec();
}

void MainWindow::on_Out_clicked()
{
    outi = new Out(this);
    outi->exec();
}

void MainWindow::on_Search_clicked()
{
    searchi = new Search(this);
    searchi->show();
}

void MainWindow::on_ext_clicked()
{
    close();
}
