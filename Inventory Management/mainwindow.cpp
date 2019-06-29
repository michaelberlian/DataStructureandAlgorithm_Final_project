#include "mainwindow.h"
#include "ui_mainwindow.h"

// this was the default constructor when we create new qt designer form class
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


// this was the default destructor when we create new qt designer form class
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_item_clicked()
{
    // create the object of the new window
    addi = new Add_item(this);
    // this use to pop the new window
    addi->exec();
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
    // same with exec but in show you still can make interaction with the window before
    searchi->show();
}

void MainWindow::on_ext_clicked()
{
    close();
}
