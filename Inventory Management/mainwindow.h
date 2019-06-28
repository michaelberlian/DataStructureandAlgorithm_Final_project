#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "add_item.h"
#include "edit_item.h"
#include "delete_item.h"
#include "in.h"
#include "out.h"
#include "search.h"
#include "data.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Add_item_clicked();

    void on_Edit_item_clicked();

    void on_del_clicked();

    void on_In_clicked();

    void on_Out_clicked();

    void on_Search_clicked();

    void on_ext_clicked();

private:
    Ui::MainWindow *ui;
    Add_item *addi;
    Edit_item *editi;
    Delete_item *deletei;
    In *ini;
    Out *outi;
    Search *searchi;
    Storage main_storage;
};

#endif // MAINWINDOW_H
