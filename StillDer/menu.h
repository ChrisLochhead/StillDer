#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "menuitem.h"

#include "tree.h"

struct Tree{

    Tree(TreeNode* r);

    QVector<MenuItem> inOrderTraversal();
    QVector<MenuItem> inOrderTraversal(QVector<MenuItem> orderedMenu, TreeNode* current);

    TreeNode* root;
    QString name;


};

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

    void addNode(TreeNode* current, MenuItem* item, int pos);

    Tree* getTree()
    {
        return AlphabeticalTree;
    }

    void setInOrderTree(QVector<MenuItem> newTree)
    {
        inOrderTree = newTree;
    }

    QVector<MenuItem> getInOrderTree()
    {
        return inOrderTree;
    }

private:

    QString menuName;
    QVector<MenuItem> items;

    Tree* AlphabeticalTree;

    //tree sort data
    QVector<MenuItem> inOrderTree;
};

#endif // MENU_H
