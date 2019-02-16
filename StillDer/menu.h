#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "menuitem.h"

struct Menu{

    Menu();
    QVector<MenuItem> getMenu();
    void setMenu(MenuItem m )
    {
        items.push_back(m);
    }
    void setName(QString n);
    QString getName()
    {
        return menuName;
    }
private:

    QString menuName;
    QVector<MenuItem> items;
};

#endif // MENU_H
