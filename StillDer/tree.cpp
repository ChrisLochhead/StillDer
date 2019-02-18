#include "menu.h"


Tree::Tree(TreeNode* r)
{
    root = new TreeNode(nullptr, r->getItem());

}

QVector<MenuItem> Tree::inOrderTraversal(QVector<MenuItem> orderedMenu, TreeNode *current)
{
    if(current == nullptr) return orderedMenu;

        inOrderTraversal(orderedMenu, current->getChildren(0));

        qInfo() << current->getItem()->name;
        orderedMenu.push_back(*current->getItem());

        inOrderTraversal(orderedMenu, current->getChildren(1));
        return orderedMenu;
    }
QVector<MenuItem> Tree::inOrderTraversal()
{

    QVector<MenuItem> inOrderMenu;

    //if the tree has a root
    if(root != nullptr)
    {
        // go into recursive function
        inOrderMenu = inOrderTraversal(inOrderMenu, root);

    }
    else  // if there is no tree in this object
    {
            qInfo() << "No tree detected" <<endl;
            return inOrderMenu;
    }
    qInfo() << "Tree sucessfully parsed" <<endl;
    return inOrderMenu;
}
