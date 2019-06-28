#include "add_item.h"
#include "ui_add_item.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

Add_item::Add_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_item)
{
    ui->setupUi(this);
    bool open = storage.read("source.txt");
    if (!open){
        ui->error->setText("cannot open the source file");
    }
}

Add_item::~Add_item()
{
    delete ui;
}

void Add_item::on_OK_clicked()
{
    string id = ui->Id->text().toStdString();
    if (id.find(" ") != std::string::npos){
        ui->error->setText("id cant have space");
        return;
    }
    string name = ui->Name->text().toStdString();
    int price = ui->Price->text().toInt();
    int qty = ui->Qty->text().toInt();
    if (id != "" && name != "" && price != 0 && qty != 0){
        if (!storage.find_id(id)){
            storage.add(Item(id,name,price,qty));
            ids.push_back(id);
            ui->error->setText("Successfully Added.");
            ui->Id->setText("");
            ui->Name->setText("");
            ui->Price->setText("");
            ui->Qty->setText("");
        }
        else {
            ui->error->setText("Id has already used.");
        }
    }
    else {
        ui->error->setText("check input");
    }
}

void Add_item::closeEvent(QCloseEvent *){
    on_Cancel_clicked();
}

void Add_item::on_Cancel_clicked()
{
    storage.write("source.txt");
    close();
}

void Add_item::on_Add_item_rejected()
{
    on_Cancel_clicked();
}
