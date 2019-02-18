#include "menu.h"


Tree::Tree(TreeNode* r)
{
    root = new TreeNode(nullptr, r->getItem());

}

void Tree::inOrderTraversal(TreeNode *current)
{
    if(current != nullptr){

        inOrderTraversal(current->getChildren(0));

        qInfo() << current->getItem()->name;
        inOrderTree.push_back(*current->getItem());
        qInfo() << inOrderTree.size();
        inOrderTraversal(current->getChildren(1));
    }
}
void Tree::inOrderTraversal()
{


    //if the tree has a root
    if(root != nullptr)
    {
        // go into recursive function
        inOrderTraversal(root);

    }
    else  // if there is no tree in this object
    {
        qInfo() << "No tree detected" <<endl;

    }
        qInfo() << "Tree sucessfully parsed" <<endl;
}
