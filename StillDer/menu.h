#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "menuitem.h"

#include "tree.h"

struct Tree{

    Tree(TreeNode* r);

    void inOrderTraversal();
    void inOrderTraversal(TreeNode* current);

    TreeNode* root;
    QString name;

    QVector<MenuItem> inOrderTree;


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

    void createTrees(int treeType);

    void addNode(TreeNode* current, MenuItem* item, int pos, int treetype);

    Tree* getTree(int treeType)
    {
        if(treeType == 0)
        return AlphabeticalTree;
        if(treeType == 1)
        return CodeTree;
        if(treeType == 2)
        return PriceTree;

    }

    QVector<MenuItem> getInOrderTree()
    {
        return AlphabeticalTree->inOrderTree;
    }

private:

    QString menuName;
    QVector<MenuItem> items;

    Tree* AlphabeticalTree;
    Tree* PriceTree;
    Tree* CodeTree;

};

#endif // MENU_H
