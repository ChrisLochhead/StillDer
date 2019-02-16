#ifndef NEWORDERWINDOW_H
#define NEWORDERWINDOW_H

#include <QDialog>
#include <QScrollBar>
#include <QDebug>
#include <QListWidgetItem>
#include <QDateTime>
#include "user.h"

namespace Ui {
class NewOrderWindow;
}

class NewOrderWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewOrderWindow(QWidget *parent = nullptr);
    ~NewOrderWindow();

    void setUser(User* u)
    {
        user = u;
    }

    void setMenus();

private slots:
    void on_Close_clicked();

    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Save_clicked();

private:
    Ui::NewOrderWindow *ui;

    User* user;

    int noOfItems = 0;
    double orderPrice = 0;
};

#endif // NEWORDERWINDOW_H
