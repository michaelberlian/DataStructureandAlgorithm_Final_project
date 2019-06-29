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
    // read the source file
    bool open = storage.read("source.txt");
    // if file cannot be open
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
    // get the id from the text label
    string id = ui->Id->text().toStdString();
    //id cant have space validation
    if (id.find(" ") != std::string::npos){
        ui->error->setText("id cant have space");
        return;
    }
    // get the inputs
    string name = ui->Name->text().toStdString();
    int price = ui->Price->text().toInt();
    int qty = ui->Qty->text().toInt();
    // validations
    if (id != "" && name != "" && price != 0 && qty != 0){
        // if id is unique
        if (!storage.find_id(id)){
            // add into storage
            storage.add(Item(id,name,price,qty));
            ids.push_back(id);
            // clear the labels
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
// when x is clicked
void Add_item::closeEvent(QCloseEvent *){
    on_Cancel_clicked();
}
// cancel button clicked
void Add_item::on_Cancel_clicked()
{
    // write the storage into txt file
    storage.write("source.txt");
    // close the window
    close();
}
// esc button pressed
void Add_item::on_Add_item_rejected()
{
    on_Cancel_clicked();
}
