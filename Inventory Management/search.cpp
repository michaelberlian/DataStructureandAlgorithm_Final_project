#include "search.h"
#include "ui_search.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <algorithm>

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    QStringList header;
    header << "Id" << "Name" << "Price" << "Quantity";
    ui->Table->setColumnCount(4);
    ui->Table->setHorizontalHeaderLabels(header);
}

Search::~Search()
{
    delete ui;
}

void Search::on_Back_clicked()
{
    close();
}

void Search::on_Src_clicked()
{
    string id,name,price,qty;

    ui->Table->clearContents();
    ui->Table->setRowCount(0);

    storage.empty();

    storage.read("source.txt");

    vector<Item> vec = storage.get_vector();

    string id_search,name_search;
    id_search = ui->Id->text().toStdString();
    name_search = ui->Name->text().toStdString();
    std::transform(id_search.begin(),id_search.end(),id_search.begin(),::tolower);
    std::transform(name_search.begin(),name_search.end(),name_search.begin(),::tolower);

    for (vector<Item>::iterator it = vec.begin(); it != vec.end(); it++ ){
        string id = it->get_id();
        string name = it->get_name();
        std::transform(id.begin(),id.end(),id.begin(),::tolower);
        std::transform(name.begin(),name.end(),name.begin(),::tolower);
        if (id.find(id_search) != std::string::npos && name.find(name_search) != std::string::npos){
            id = it->get_id();
            name = it->get_name();
            price = to_string(it->get_price());
            qty = to_string(it->get_quantity());
            ui->Table->insertRow(ui->Table->rowCount());
            int col = ui->Table->rowCount()-1;
            ui->Table->setItem(col,ID,new QTableWidgetItem(QString::fromStdString(id)));
            ui->Table->setItem(col,NAME,new QTableWidgetItem(QString::fromStdString(name)));
            ui->Table->setItem(col,PRICE,new QTableWidgetItem(QString::fromStdString(price)));
            ui->Table->setItem(col,QTY,new QTableWidgetItem(QString::fromStdString(qty)));
        }
    }
}
