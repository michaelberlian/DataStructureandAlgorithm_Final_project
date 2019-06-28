#include "out.h"
#include "ui_out.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

Out::Out(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Out)
{
    ui->setupUi(this);
    bool open = storage.read("source.txt");
    if (!open){
        ui->error->setText("cannot open the source file");
    }
}

Out::~Out()
{
    delete ui;
}

void Out::on_OK_clicked()
{
    if (ui->Id->text() != "" && ui->Name->text()!= "" && ui->Input->text()!= "" && ui->Qty->text()!=""){
        if (QString::fromStdString(now->get_id()) == ui->Id->text()){
            if (ui->Qty->text().toInt() >= ui->Input->text().toInt()){
                storage.sell_stock(ui->Id->text().toStdString(),ui->Input->text().toInt());
                ui->error->setText("Updated Successfully");
                ui->Id->setText("");
                ui->Name->setText("");
                ui->Qty->setText("");
                ui->Input->setText("");
            }
            else{
                ui->error->setText("Out bigger than Quantity");
                ui->Input->setText("");
            }
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

void Out::closeEvent(QCloseEvent *){
    on_Cancel_clicked();
}

void Out::on_Cancel_clicked()
{
    storage.write("source.txt");
    close();
}

void Out::on_Search_clicked()
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

void Out::on_Out_rejected()
{
    on_Cancel_clicked();
}
