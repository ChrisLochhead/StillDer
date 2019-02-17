#ifndef TREE_H
#define TREE_H

#include <QString>
#include <QDebug>
#include "menuitem.h"

class TreeNode{

public:

    TreeNode(TreeNode* p, MenuItem *i);

    TreeNode* getParent();
    TreeNode* getChildren(int i);
    void addChild(TreeNode *c, int pos);

    MenuItem* getItem();

private:
    MenuItem* item = nullptr;

    TreeNode* parent;
    TreeNode* children[2];


};


#endif // TREE_H
