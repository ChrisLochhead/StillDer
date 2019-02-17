#include "menu.h"


Tree::Tree(TreeNode* r)
{
    root = new TreeNode(nullptr, r->getItem());

}

QString Tree::inOrderTraversal(QString orderString, TreeNode *current)
{
    if(current!= nullptr && current->getChildren(0) != nullptr){
    inOrderTraversal(orderString, current->getChildren(0));
    }
    if(current != nullptr){
    qInfo() << current->getItem()->name;
    orderString += current->getItem()->name;
    }
    if(current != nullptr && current->getChildren(1) != nullptr){
    inOrderTraversal(orderString, current->getChildren(1));
    }
    return orderString;
}
QString Tree::inOrderTraversal()
{

    QString orderString;

    //if the tree has a root
    if(root != nullptr)
    {
        orderString = root->getItem()->name;

        if(root->getChildren(0)!= nullptr){

            orderString += inOrderTraversal(orderString, root->getChildren(0));
        }
        else
        {
            orderString += inOrderTraversal(orderString, root->getChildren(1));
        }
    }
    else  // if there is no tree in this object
    {
        return "No tree detected";
    }

    return orderString;
}
