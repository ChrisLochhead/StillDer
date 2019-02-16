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
