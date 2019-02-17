#include "menu.h"


Menu::Menu()
{

}

QVector<MenuItem> Menu::getMenu()
{
    return items;
}

void Menu::setName(QString n)
{
    menuName = n;
}

void Menu::createTrees()
{
        QVector<MenuItem>::iterator it;

        for (it = items.begin(); it != items.end(); ++it) {


            if(it == items.begin())
            {
                TreeNode* rootNode = new TreeNode(nullptr, it);
                AlphabeticalTree = new Tree(rootNode);
                qInfo() << rootNode->getItem()->name << endl;
            }
            else
            {  // if the name is closer to the start alphabetically than the root.
                TreeNode* tempNode = AlphabeticalTree->root;
                MenuItem* tmp = tempNode->getItem();

                //it cant go first for some stupid fucking reason
               if(QString::compare(tmp->name, it->name, Qt::CaseInsensitive) < 0){

                   //then, if there is no child closer to A than this node
                   if(tempNode->getChildren(1) == nullptr){
                   //create a new node with the root as its parent, effectively adding it to the tree.
                   TreeNode* node = new TreeNode(tempNode, it);
                   tempNode->addChild(node, 1);
                   qInfo() << node->getItem()->name << endl;
                   }else
                   {
                       //call recursive function to search the tree for empty nodes
                       addNode(tempNode, it, 1);
                   }

               }
               else
               {   // if the name is closer to the end alphabetically than the root

                   if(AlphabeticalTree->root->getChildren(0) == nullptr){
                   //create a new node with the root as its parent, effectively adding it to the tree.
                   TreeNode* node = new TreeNode(tempNode, it);
                   tempNode->addChild(node, 0);
                   qInfo() << node->getItem()->name << endl;
                   }else
                   {
                       //call recursive function to search the tree for empty nodes
                       addNode(tempNode, it, 0);
                   }
               }
            }



        }
}


void Menu::addNode(TreeNode *current, MenuItem* item, int pos)
{
//going left
if(pos == 0)
{
    if(current->getChildren(0) == nullptr)
    {
        TreeNode* node = new TreeNode(current, item);
        current->addChild(node, 0);
        qInfo() << node->getItem()->name << endl;
    }else{

        TreeNode* tempNode = current->getChildren(0);
        MenuItem* tmp = tempNode->getItem();

        if(QString::compare(tmp->name, item->name, Qt::CaseInsensitive) < 0 )
        {//existing child is smaller than current item)
            addNode(tempNode, item, 1);
        }
        else
        { // existing child is bigger than current item
            addNode(tempNode, item, 0);
        }
    }

}
else   // going right
{

    if(current->getChildren(1) != nullptr)
    {
        TreeNode* tempNode = current->getChildren(1);
        MenuItem* tmp = tempNode->getItem();

        if(QString::compare(tmp->name, item->name, Qt::CaseInsensitive) < 0 )
        {//existing child is smaller than current item)
            addNode(tempNode, item, 1);
        }
        else
        { // existing child is bigger than current item
            addNode(tempNode, item, 0);
        }
    }else{
            TreeNode* node = new TreeNode(current, item);
            current->addChild(node, 1);
            qInfo() << node->getItem()->name << endl;
    }
}

}
