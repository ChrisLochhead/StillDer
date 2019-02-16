#ifndef USER_H
#define USER_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QDebug>
#include "menu.h"

struct User{

    User()
    {
    }
    void setDetails(QString name, QString pass)
    {
        username = name;
        password = pass;
    }
    QString getUser(){return username;}
    QString getPass(){return password;}
    QVector<Menu> getMenus(){return registeredMenus;}

    void setMenu(Menu newMenu)
    {
        registeredMenus.push_back(newMenu);
    }

    QVector<QString> getFiles()
    {
        return menuFiles;
    }

    void loadMenus()
    {
        Menu m;
        //load any existing menus
        QDir dir("C:/Users/chris/OneDrive/Documents/AlgorithmsProject/StillDer/SavedMenus/" + username);

        QDirIterator it(dir.path(), QStringList() << "*.txt", QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QFile f(it.next());
            if(!f.open(QFile::ReadOnly | QFile::Text))
            {
                //find a way to change style sheet of warning message
                qInfo() << "my name is jeffrey";
            }

            int lineCount = 0;
            QString line[300];

            while(!f.atEnd())
            {

            //count the number of menu items by line


            QString menuName;

            QString name;
            QString code;
            QString unit;
            QString price;
            line[lineCount] = f.readLine();

            if(lineCount == 0)
            {
                menuName = line[lineCount];
                m.setName(menuName);
            }

            if(lineCount > 2){

            QStringList lineList = line[lineCount].split(",");

            code =  lineList.value(0);
            name =  lineList.value(1);
            unit =  lineList.value(2);
            price =  lineList.value(3);
            qInfo()<< "Menu information : " << name;

            MenuItem *item = new MenuItem(code, name, unit, price);

            m.setMenu(*item);
            }

            lineCount++;
            }
            registeredMenus.push_back(m);
        }
    }
private:

    QVector<Menu> registeredMenus;
    QVector<QString> menuFiles;
    QString username;
    QString password;



};

#endif // USER_H
