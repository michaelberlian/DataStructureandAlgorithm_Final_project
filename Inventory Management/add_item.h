#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <QDialog>
#include "data.h"
#include <vector>
using namespace std;

namespace Ui {
class Add_item;
}

class Add_item : public QDialog
{
    Q_OBJECT

public:
    explicit Add_item(QWidget *parent = nullptr);
    ~Add_item();

private slots:
    void on_OK_clicked();

    void on_Cancel_clicked();

    void closeEvent(QCloseEvent *);

    void on_Add_item_rejected();

private:
    Ui::Add_item *ui;
    Storage storage;
    vector<string> ids;
};

#endif // ADD_ITEM_H
