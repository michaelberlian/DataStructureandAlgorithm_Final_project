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
    // prepare the table
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
    // clear the table row
    ui->Table->clearContents();
    ui->Table->setRowCount(0);

    // reread the file
    storage.empty();
    storage.read("source.txt");

    // take the vector
    vector<Item> vec = storage.get_vector();

    string id_search,name_search;
    id_search = ui->Id->text().toStdString();
    name_search = ui->Name->text().toStdString();
    // to make the search not case sensitive
    std::transform(id_search.begin(),id_search.end(),id_search.begin(),::tolower);
    std::transform(name_search.begin(),name_search.end(),name_search.begin(),::tolower);

    for (vector<Item>::iterator it = vec.begin(); it != vec.end(); it++ ){
        string id = it->get_id();
        string name = it->get_name();
        // to make the seach not case sensitive
        std::transform(id.begin(),id.end(),id.begin(),::tolower);
        std::transform(name.begin(),name.end(),name.begin(),::tolower);
        if (id.find(id_search) != std::string::npos && name.find(name_search) != std::string::npos){
            // if the id and the name have the search criteria
            id = it->get_id();
            name = it->get_name();
            price = to_string(it->get_price());
            qty = to_string(it->get_quantity());
            // insert the row
            ui->Table->insertRow(ui->Table->rowCount());
            int col = ui->Table->rowCount()-1;
            // fill the row in
            ui->Table->setItem(col,0,new QTableWidgetItem(QString::fromStdString(id)));
            ui->Table->setItem(col,1,new QTableWidgetItem(QString::fromStdString(name)));
            ui->Table->setItem(col,2,new QTableWidgetItem(QString::fromStdString(price)));
            ui->Table->setItem(col,3,new QTableWidgetItem(QString::fromStdString(qty)));
        }
    }
}
