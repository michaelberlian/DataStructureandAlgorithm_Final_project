#ifndef IN_H
#define IN_H

#include <QDialog>
#include "data.h"
#include <vector>

namespace Ui {
class In;
}

class In : public QDialog
{
    Q_OBJECT

public:
    explicit In(QWidget *parent = nullptr);
    ~In();

private slots:
    void on_Add_clicked();

    void on_Cancel_clicked();

    void on_Search_clicked();

    void closeEvent(QCloseEvent *);
private:
    Ui::In *ui;
    Storage storage;
    Item *now;
};

#endif // IN_H
