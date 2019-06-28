#include "in.h"
#include "ui_in.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

In::In(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::In)
{
    ui->setupUi(this);
    bool open = storage.read("source.txt");
    if (!open){
        ui->error->setText("cannot open the source file");
    }
}

In::~In()
{
    delete ui;
}

void In::on_Add_clicked()
{
    if (ui->Id->text() != "" && ui->Name->text()!= "" && ui->Input->text()!= "" && ui->Qty->text()!=""){
        if (QString::fromStdString(now->get_id()) == ui->Id->text()){
            storage.add_stock(ui->Id->text().toStdString(),ui->Input->text().toInt());
            ui->error->setText("added Successfully");
            ui->Id->setText("");
            ui->Name->setText("");
            ui->Qty->setText("");
            ui->Input->setText("");
        }
        else {
            ui->error->setText("Click Search Before save");
            ui->Name->setText("");
            ui->Qty->setText("");
            ui->Input->setText("");
        }
    }
    else {
        ui->error->setText("Check Input");
    }
}

void In::closeEvent(QCloseEvent *){
    on_Cancel_clicked();
}

void In::on_Cancel_clicked()
{
    storage.write("source.txt");
    close();
}

void In::on_Search_clicked()
{
    ui->error->setText("");
    string id = ui->Id->text().toStdString();
    ui->Name->setText("");
    ui->Qty->setText("");
    ui->Input->setText("");
    if (storage.find_id(id)){
        now = storage.get_id(id);
        ui->Name->setText(QString::fromStdString(now->get_name()));
        ui->Qty->setText(QString::number(now->get_quantity()));
    }
    else{
        ui->error->setText("ID NOT FOUND");
    }
}
