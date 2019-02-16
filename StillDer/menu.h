#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "menuitem.h"
#include "tree.h"

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

    void createTrees();

    void addNode(TreeNode* current, MenuItem* item);

private:

    QString menuName;
    QVector<MenuItem> items;

    Tree* AlphabeticalTree;
};

#endif // MENU_H
