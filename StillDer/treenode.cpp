#include "tree.h"

TreeNode::TreeNode(TreeNode* p, MenuItem *i)
{
    parent = p;
    item = new MenuItem(i->code, i->name, i->unit, i->price);
    children[0] = nullptr;
    children[1] = nullptr;
}
TreeNode* TreeNode::getParent()
{
    return parent;
}
TreeNode* TreeNode::getChildren(int i)
{
    return children[i];
}

void TreeNode::addChild(TreeNode *c, int pos)
{
   children[pos] = c;
   qInfo() << children[pos]->getItem()->name << endl;
}

MenuItem* TreeNode::getItem()
{
    return item;
}
