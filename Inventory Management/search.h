#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include "data.h"
#include <vector>
#include <QTableWidgetItem>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

private slots:
    void on_Back_clicked();
    void on_Src_clicked();

private:
    Ui::Search *ui;
    Storage storage;
    enum colomn{
        ID,NAME,PRICE,QTY
    };
};

#endif // SEARCH_H
