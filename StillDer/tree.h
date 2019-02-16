#ifndef TREE_H
#define TREE_H

#include <QString>
#include <menu.h>

class TreeNode{

public:
    TreeNode(TreeNode* p, MenuItem* i);

    TreeNode* getParent();
    TreeNode* getChildren(int i);

    void addChild(TreeNode* c, int pos);

    MenuItem* getItem()
    {
        return item;
    }

private:
    MenuItem* item;

    TreeNode* parent;
    TreeNode* children[2];


};

struct Tree{
    Tree(TreeNode* r);

    TreeNode* root;
    QString name;

};

#endif // TREE_H
