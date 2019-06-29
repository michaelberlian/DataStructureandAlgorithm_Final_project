#include "delete_item.h"
#include "ui_delete_item.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

Delete_item::Delete_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete_item)
{
    ui->setupUi(this);
    // read file
    bool open = storage.read("source.txt");
    if (!open){
        ui->error->setText("cannot open the source file");
    }
}

Delete_item::~Delete_item()
{
    delete ui;
}

void Delete_item::on_Delete_clicked()
{
    // validations
    if (ui->Id->text() != "" && ui->Name->text()!= "" && ui->Price->text()!= "" && ui->Qty->text()!=""){
        if (QString::fromStdString(now->get_id()) == ui->Id->text()){
            storage.del(ui->Id->text().toStdString());
            ui->error->setText("Delete Successfully");
            ui->Id->setText("");
            ui->Name->setText("");
            ui->Price->setText("");
            ui->Qty->setText("");
        }
        else {
            ui->error->setText("Click Search Before Delete");
            ui->Name->setText("");
            ui->Price->setText("");
            ui->Qty->setText("");
        }
    }
    else {
        ui->error->setText("Check Input.");
    }
}
// x clicked
void Delete_item::closeEvent(QCloseEvent *){
    on_Cancel_clicked();
}
// cancel button clicked
void Delete_item::on_Cancel_clicked()
{
    // write the storage into txt file
    storage.write("source.txt");
    // close the window
    close();
}

void Delete_item::on_Search_clicked()
{
    ui->error->setText("");
    ui->Name->setText("");
    ui->Price->setText("");
    ui->Qty->setText("");
    string id = ui->Id->text().toStdString();
    // find the id
    if (storage.find_id(id)){
        // if found get the pointer to it
        now = storage.get_id(id);
        ui->Name->setText(QString::fromStdString(now->get_name()));
        ui->Price->setText(QString::number(now->get_price()));
        ui->Qty->setText(QString::number(now->get_quantity()));
    }
    else{
        ui->error->setText("ID NOT FOUND");
    }
}
//esc button pressed
void Delete_item::on_Delete_item_rejected()
{
    on_Cancel_clicked();
}
