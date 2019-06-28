#ifndef EDIT_ITEM_H
#define EDIT_ITEM_H

#include <QDialog>
#include "data.h"
#include <vector>

namespace Ui {
class Edit_item;
}

class Edit_item : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_item(QWidget *parent = nullptr);
    ~Edit_item();

private slots:
    void on_Save_clicked();

    void on_Cancel_clicked();

    void on_Search_clicked();

    void closeEvent(QCloseEvent *);

private:
    Ui::Edit_item *ui;
    Storage storage;
    Item *now;
};

#endif // EDIT_ITEM_H
