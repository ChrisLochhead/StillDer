#ifndef MENUITEM_H
#define MENUITEM_H

#include <QString>

struct MenuItem {

    MenuItem(){}
    MenuItem(QString c, QString n, QString u, QString p)
    {
        code = c;
        name = n;
        unit = u;
        price = p;

    }
    QString code;
    QString name;
    QString unit;
    QString price;

};

#endif // MENUITEM_H
