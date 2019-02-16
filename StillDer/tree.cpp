#include "tree.h"


TreeNode::TreeNode(TreeNode* p, MenuItem* i)
{
    parent = p;
    item = i;
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
}

Tree::Tree(TreeNode* r)
{
    root = r;
}
