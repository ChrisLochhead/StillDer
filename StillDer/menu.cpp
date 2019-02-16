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
            }
            else
            {  // if the name is closer to the start alphabetically than the root.
               if(it->name.compare(AlphabeticalTree->root->getItem()->name) < 0){

                   //then, if there is no child closer to A than this node
                   if(AlphabeticalTree->root->getChildren(0) == nullptr){
                   //create a new node with the root as its parent, effectively adding it to the tree.
                   TreeNode* node = new TreeNode(AlphabeticalTree->root, it);
                   }else
                   {
                       //call recursive function to search the tree for empty nodes
                       addNode(AlphabeticalTree->root->getChildren(0), it);
                   }

               }
               else
               {   // if the name is closer to the end alphabetically than the root

                   if(AlphabeticalTree->root->getChildren(1) == nullptr){
                   //create a new node with the root as its parent, effectively adding it to the tree.
                   TreeNode* node = new TreeNode(AlphabeticalTree->root, it);
                   }else
                   {
                       //call recursive function to search the tree for empty nodes
                       addNode(AlphabeticalTree->root->getChildren(1), it);
                   }
               }
            }



        }
}


void Menu::addNode(TreeNode *current, MenuItem* item)
{
    if(item->name.compare(current->getItem()->name) < 0){

        //then, if there is no child closer to A than this node
        if(current->getChildren(0) == nullptr){
        //create a new node with the root as its parent, effectively adding it to the tree.
        TreeNode* node = new TreeNode(current, item);
        }else
        {
            //call recursive function to search the tree for empty nodes
            addNode(current->getChildren(0), item);
        }

    }
    else
    {   // if the name is closer to the end alphabetically than the root

        if(AlphabeticalTree->root->getChildren(1) == nullptr){
        //create a new node with the root as its parent, effectively adding it to the tree.
        TreeNode* node = new TreeNode(current, item);
        }else
        {
            //call recursive function to search the tree for empty nodes
            addNode(current->getChildren(1), item);
        }
    }

}
