#include "edit_item.h"
#include "ui_edit_item.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


Edit_item::Edit_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_item)
{
    ui->setupUi(this);
    bool open = storage.read("source.txt");
    if (!open){
        ui->error->setText("cannot open the source file");
    }
}

Edit_item::~Edit_item()
{

    delete ui;
}

void Edit_item::on_Save_clicked()
{
    if (ui->Id->text() != "" && ui->Name->text()!= "" && ui->Price->text()!= ""){
        if (QString::fromStdString(now->get_id()) == ui->Id->text()){
            now->set_name(ui->Name->text().toStdString());
            now->set_price(ui->Price->text().toInt());
            ui->error->setText("Save Successfully");
            ui->Id->setText("");
            ui->Name->setText("");
            ui->Price->setText("");
        }
        else {
            ui->error->setText("Click Search Before save");
            ui->Name->setText("");
            ui->Price->setText("");
        }
    }
    else {
        ui->error->setText("Check Input");
    }
}

void Edit_item::closeEvent(QCloseEvent *){
    on_Cancel_clicked();
}

void Edit_item::on_Cancel_clicked()
{
    storage.write("source.txt");
    close();
}

void Edit_item::on_Search_clicked()
{
    ui->error->setText("");
    string id = ui->Id->text().toStdString();
    if (storage.find_id(id)){
        now = storage.get_id(id);
        ui->Name->setText(QString::fromStdString(now->get_name()));
        ui->Price->setText(QString::number(now->get_price()));
    }
    else{
        ui->error->setText("ID NOT FOUND");
    }
}

void Edit_item::on_Edit_item_rejected()
{
    on_Cancel_clicked();
}
