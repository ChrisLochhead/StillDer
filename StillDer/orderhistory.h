#ifndef ORDERHISTORY_H
#define ORDERHISTORY_H

#include <QDialog>
#include "user.h"
#include "items.h"

namespace Ui {
class OrderHistory;
}

class OrderHistory : public QDialog
{
    Q_OBJECT

public:
    explicit OrderHistory(QWidget *parent = nullptr);
    ~OrderHistory();

    void setUser(User* u)
    {
        user = u;
    }

    void setOrders();

private slots:
    void on_Close_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::OrderHistory *ui;
    User* user;

    QVector<Menu> pastOrders;
};

#endif // ORDERHISTORY_H
