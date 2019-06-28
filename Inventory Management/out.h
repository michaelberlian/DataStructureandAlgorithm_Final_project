#ifndef OUT_H
#define OUT_H

#include <QDialog>
#include "data.h"
#include <vector>

namespace Ui {
class Out;
}

class Out : public QDialog
{
    Q_OBJECT

public:
    explicit Out(QWidget *parent = nullptr);
    ~Out();

private slots:
    void on_OK_clicked();
    void on_Cancel_clicked();
    void closeEvent(QCloseEvent *);

    void on_Search_clicked();

private:
    Ui::Out *ui;
    Storage storage;
    Item *now;
};

#endif // OUT_H
