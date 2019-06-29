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
    //read file
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
    // validations
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
// x clicked
void In::closeEvent(QCloseEvent *){
    on_Cancel_clicked();
}
// cancel button clicked
void In::on_Cancel_clicked()
{
    // write the storage into txt file
    storage.write("source.txt");
    // close the window
    close();
}

void In::on_Search_clicked()
{
    // find the item
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
// esc pressed
void In::on_In_rejected()
{
    on_Cancel_clicked();
}
