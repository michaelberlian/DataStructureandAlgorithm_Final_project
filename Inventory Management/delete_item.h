#ifndef DELETE_ITEM_H
#define DELETE_ITEM_H

#include <QDialog>
#include "data.h"
#include <vector>

namespace Ui {
class Delete_item;
}

class Delete_item : public QDialog
{
    Q_OBJECT

public:
    explicit Delete_item(QWidget *parent = nullptr);
    ~Delete_item();

private slots:
    void on_Delete_clicked();

    void on_Cancel_clicked();

    void on_Search_clicked();

    void closeEvent(QCloseEvent *);
    void on_Delete_item_rejected();

private:
    Ui::Delete_item *ui;
    Storage storage;
    Item *now;
};

#endif // DELETE_ITEM_H
