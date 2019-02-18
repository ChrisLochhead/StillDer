#include "menu.h"

//empty constructor
Menu::Menu()
{

}

//return a vector of items representing the menu
QVector<MenuItem> Menu::getMenu()
{
    return items;
}

//set the name of the menu
void Menu::setName(QString n)
{
    menuName = n;
}

//create any tree ordered by price, code or name
void Menu::createTrees(int treeType)
{
    //entry condition, dont continue unless it is one of the three predefined types
    if(treeType == 0 | treeType == 1 | treeType == 2){

    //declare a vector iterator for this menus items
    QVector<MenuItem>::iterator it;

        //cycle through the items
        for (it = items.begin(); it != items.end(); ++it) {

            // if this is the first loop
            if(it == items.begin())
            {
                //create a new rootnode
                TreeNode* rootNode = new TreeNode(nullptr, it);

                //then, according to which type of tree is being built, assign the root to one of the menus forest of trees
                if(treeType == 0)
                {
                    AlphabeticalTree = new Tree(rootNode);
                }
                if(treeType == 1)
                {
                    CodeTree = new Tree(rootNode);
                }
                if(treeType == 2)
                {
                    PriceTree = new Tree(rootNode);
                }

            }
            else
            {
                //if this isn't the root node, create a temporary node and assign it to the corresponding tree
                TreeNode* tempNode;
                if(treeType == 0) tempNode = AlphabeticalTree->root;
                if(treeType == 1) tempNode = CodeTree->root;
                if(treeType == 2) tempNode = PriceTree->root;

                //get the item data from the menu
                MenuItem* tmp = tempNode->getItem();

                //assign local variables for getting the variables that are to be compared
                QString a; QString b; float fa; float fb;

                if(treeType == 0) {  a = tmp->name;  b = it->name; }
                if(treeType == 1) {  a = tmp->code;  b = it->code; }
                if(treeType == 2) {  fa = tmp->price.toFloat(); fb = it->price.toFloat(); }

                //if the variables to be calculated are either code or name (both strings)
                if(treeType ==0 | treeType == 1){

                // find out which of the two is closer to A alphabetically
                if(QString::compare(a, b, Qt::CaseInsensitive) < 0){

                   //then, if there is no child closer to A than this node
                   if(tempNode->getChildren(1) == nullptr){

                       //create a new node with the root as its parent, effectively adding it to the tree.
                       TreeNode* node = new TreeNode(tempNode, it);
                       tempNode->addChild(node, 1);

                   }
                   else
                   {
                       //call recursive function to search the tree for empty nodes
                       addNode(tempNode, it, 1, treeType);
                   }

               }
               else
               {   // if the variable is closer to Z than the root

                   if(tempNode->getChildren(0) == nullptr){

                       //create a new node with the root as its parent, effectively adding it to the tree.
                       TreeNode* node = new TreeNode(tempNode, it);
                       tempNode->addChild(node, 0);

                   }
                   else
                   {
                       //call recursive function to search the tree for empty nodes
                       addNode(tempNode, it, 0, treeType);
                   }
               }
          }
          else
              if(treeType == 2){ // the same routine just using two floats as the variables instead of two strings

                  if(fa < fb){

                    //then, if there is no child closer to 0 than this node
                    if(tempNode->getChildren(1) == nullptr){

                    //create a new node with the root as its parent, effectively adding it to the tree.
                    TreeNode* node = new TreeNode(tempNode, it);
                    tempNode->addChild(node, 1);

                   }
                   else
                   {
                        //call recursive function to search the tree for empty nodes
                        addNode(tempNode, it, 1, treeType);
                   }

              }
              else
              {
                    // if the name is further from 0 than the root
                    if(tempNode->getChildren(0) == nullptr){

                        //create a new node with the root as its parent, effectively adding it to the tree.
                        TreeNode* node = new TreeNode(tempNode, it);
                        tempNode->addChild(node, 0);
                     }
                     else
                     {
                        //call recursive function to search the tree for empty nodes
                        addNode(tempNode, it, 0, treeType);
                     }
                   }
                }
            }
        }
    }
}


void Menu::addNode(TreeNode *current, MenuItem* item, int pos, int treetype)
{

    //going left
    if(pos == 0)
    {
        if(current->getChildren(0) == nullptr)
        {
            TreeNode* node = new TreeNode(current, item);
            current->addChild(node, 0);
            qInfo() << node->getItem()->name << endl;
        }
        else
        {

            TreeNode* tempNode = current->getChildren(0);
            MenuItem* tmp = tempNode->getItem();
            QString a; QString b; float fa; float fb;

            if(treetype == 0) {  a = tmp->name;  b = item->name; }
            if(treetype == 1) {  a = tmp->code;  b = item->code; }
            if(treetype == 2) {  fa = tmp->price.toFloat(); fb = item->price.toFloat(); }
            if(treetype == 0 | treetype == 1){
            if(QString::compare(a, b, Qt::CaseInsensitive) < 0 )
            {
                //existing child is smaller than current item)
                addNode(tempNode, item, 1, treetype);
            }
            else
            {
                // existing child is bigger than current item
                addNode(tempNode, item, 0, treetype);
            }
            }
            else
                if (treetype == 2)
                {
                    if(fa < fb)
                    {
                         addNode(tempNode, item, 1, treetype);
                    }
                    else
                    { // existing child is bigger than current item
                        addNode(tempNode, item, 0, treetype);
                    }
                }
        }
}
else   // going right
{

    if(current->getChildren(1) != nullptr)
    {
        TreeNode* tempNode = current->getChildren(1);
        MenuItem* tmp = tempNode->getItem();
        QString a; QString b; float fa; float fb;
        if(treetype == 0) {  a = tmp->name;  b = item->name; }
        if(treetype == 1) {  a = tmp->code;  b = item->code; }
        if(treetype == 2) {  fa = tmp->price.toFloat(); fb = item->price.toFloat(); }
        if(treetype == 0 | treetype == 1){

            if(QString::compare(a, b, Qt::CaseInsensitive) < 0 )
            {
                //existing child is smaller than current item)
                addNode(tempNode, item, 1, treetype);
            }
            else
            {
                //existing child is bigger than current item
                addNode(tempNode, item, 0, treetype);
            }
        }
        else
            if(treetype == 2)
            {
                if(fa < fb )
                {   //existing child is smaller than current item)
                    addNode(tempNode, item, 1, treetype);
                }
                else
                {   //existing child is bigger than current item
                    addNode(tempNode, item, 0, treetype);
                }
            }
    }
    else
    {
        TreeNode* node = new TreeNode(current, item);
        current->addChild(node, 1);
        qInfo() << node->getItem()->name << endl;
    }
  }
}
