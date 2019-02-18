#include "orderhistory.h"
#include "ui_orderhistory.h"

OrderHistory::OrderHistory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderHistory)
{
    ui->setupUi(this);

}

OrderHistory::~OrderHistory()
{
    delete ui;
}

void OrderHistory::on_Close_clicked()
{
    this->~OrderHistory();
}

void OrderHistory::setOrders()
{

    //load any existing menus
    QDir dir("C:/Users/chris/OneDrive/Documents/AlgorithmsProject/StillDer/SavedOrders/" + user->getUser());

    QDirIterator it(dir.path(), QStringList() << "*.txt", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QFile f(it.next());
        if(!f.open(QFile::ReadOnly | QFile::Text))
        {
            //find a way to change style sheet of warning message
            qInfo() << "my name is jeffrey";
        }

        //cycle through all names
        Menu m;

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
            ui->comboBox->addItem(menuName);
        }

        if(lineCount > 1){

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
        pastOrders.push_back(m);
    }
}


void OrderHistory::on_comboBox_activated(int index)
{

    ui->list->clear();

    QVector<MenuItem>::iterator it;

    qInfo() << index;

    Menu menus = pastOrders.at(index);

    QVector<MenuItem> tmpItems = menus.getMenu();

    for(it = tmpItems.begin(); it != tmpItems.end(); ++it)
    {

        QListWidgetItem* tmp = new QListWidgetItem(ui->list);

        ui->list->addItem(tmp);

        items *menuIt = new items;
        menuIt->setUnits(it->code, it->name, it->unit, it->price);
        menuIt->move(300);
        tmp->setSizeHint(QSize(490,100));

        ui->list->setItemWidget(tmp, menuIt);

    }

}
