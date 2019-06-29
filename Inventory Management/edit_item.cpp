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
    // read the files
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
    // validations
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
// x clicked
void Edit_item::closeEvent(QCloseEvent *){
    on_Cancel_clicked();
}
// cancel button clicked
void Edit_item::on_Cancel_clicked()
{
    // write the storage into txt file
    storage.write("source.txt");
    // close the window
    close();
}

void Edit_item::on_Search_clicked()
{
    ui->Name->setText("");
    ui->Price->setText("");
    ui->error->setText("");
    // find the item
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
// esc pressed
void Edit_item::on_Edit_item_rejected()
{
    on_Cancel_clicked();
}
