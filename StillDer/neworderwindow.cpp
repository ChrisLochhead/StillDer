#include "neworderwindow.h"
#include "ui_neworderwindow.h"
#include "items.h"
NewOrderWindow::NewOrderWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOrderWindow)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->Sort->addItem("Sort");
    ui->Sort->addItem("sort A-Z");

    QScrollBar* vBar = ui->OrderList->verticalScrollBar();
    vBar->setStyleSheet("QScrollBar:vertical {"
                        "    border: 1px solid #999999;"
                        "    background: none;"
                        "    width:10px;    "
                        "    margin: 0px 0px 0px 0px;"
                        "}"
                        "QScrollBar::handle:vertical {"
                        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                        "    stop: 0 rgb(200,191,231), stop: 0.5 rgb(200,191,231), stop:1 rgb(200,191,231));"
                        "    min-height: 0px;"
                        "}"
                        "QScrollBar::add-line:vertical {"
                        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                        "    stop: 0 rgb(255,255,255), stop: 0.5 rgb(255,255,255),  stop:1 rgb(255,255,255));"
                        "    height: 0px;"
                        "    subcontrol-position: bottom;"
                        "    subcontrol-origin: margin;"
                        "}"
                        "QScrollBar::sub-line:vertical {"
                        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                        "    stop: 0  rgb(255,255,255), stop: 0.5 rgb(255,255,255),  stop:1 rgb(255,255,255));"
                        "    height: 0 px;"
                        "    subcontrol-position: top;"
                        "    subcontrol-origin: margin;"
                        "}");

}

void NewOrderWindow::setMenus()
{
    //ui->MenuList->clear();

    QVector<Menu> ms = user->getMenus();

    QVector<MenuItem>::iterator it;
    QVector<Menu>::iterator itt;

    for (itt = ms.begin(); itt != ms.end(); ++itt) {


          QVector<MenuItem> mi = itt->getMenu();

         // QVector<MenuItem> mii = itt->getInOrderTree();

          ui->MenuName->setText(itt->getName());
          ui->MenuSelect->addItem(itt->getName());
          QString str = itt->getName();
          str = str.simplified();
          str.replace( " ", "" );
          ui->SelectedMenu->setText("Menu: " + str);
          ui->TotalOrderPrice->setText("Total Price: " + QString::number(orderPrice));
          QString s("Number of items: " + QString::number(noOfItems));
          ui->NoOfItems->setText(s);

         // if(ui->Sort->currentIndex() == 0){
          for(it = mi.begin(); it != mi.end(); ++it)
          {

              QListWidgetItem* tmp = new QListWidgetItem(ui->MenuList);

              ui->MenuList->addItem(tmp);

              items *menuIt = new items;
              menuIt->setUnits(it->code, it->name, it->unit, it->price);

              tmp->setSizeHint(QSize(490,100));

              ui->MenuList->setItemWidget(tmp, menuIt);
        //  }
}
    }
}
NewOrderWindow::~NewOrderWindow()
{
    delete ui;
}

void NewOrderWindow::on_Close_clicked()
{
    this->~NewOrderWindow();
}


void NewOrderWindow::on_Add_clicked()
{
    qInfo() << ui->Sort->currentIndex();
    QListWidgetItem *w = ui->MenuList->currentItem();

    items *i = dynamic_cast<items *>(ui->MenuList->itemWidget(w));
    if(i)
    qInfo() << i->getItem("code");


    QListWidgetItem* tmp = new QListWidgetItem(ui->OrderList);

    ui->OrderList->addItem(tmp);

    items *menuIt = new items;
    menuIt->setUnits(i->getItem("code"), i->getItem("name"), i->getItem("unit"), i->getItem("price"));

    tmp->setSizeHint(QSize(800,100));
    menuIt->resize(800, 100);
    menuIt->move(200);


    ui->OrderList->setItemWidget(tmp, menuIt);

    noOfItems++;
    orderPrice += i->getItem("price").toDouble();

   ui->NoOfItems->setText("Number of items: " + QString::number(noOfItems));
   ui->TotalOrderPrice->setText("Total price: " + QString::number(orderPrice));



}

void NewOrderWindow::on_Remove_clicked()
{

    if(ui->OrderList->currentItem()){
    noOfItems--;

    QListWidgetItem *w = ui->OrderList->currentItem();

    items *i = dynamic_cast<items *>(ui->OrderList->itemWidget(w));
    orderPrice -= i->getItem("price").toDouble();

    if(noOfItems == 0)
        orderPrice = 0;

    ui->NoOfItems->setText("Number of items: " + QString::number(noOfItems));
    ui->TotalOrderPrice->setText("Total price: " + QString::number(orderPrice));

        delete ui->OrderList->currentItem();
    }
}

void NewOrderWindow::on_Save_clicked()
{
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh:mm:ss");
    qInfo()<<timeText;

    QString n = timeText + "tout.txt";


    QDir dir("C:/Users/chris/OneDrive/Documents/AlgorithmsProject/StillDer/SavedOrders/" + user->getUser());
    QFile file(dir.path() + "/" + QString("%1.txt").arg(QDateTime::currentDateTime().toString("ddMMyyyy-hhmmss")));

    QString a = QString::number(ui->OrderList->count());
    qInfo() << a;

    if(file.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream txt(&file);

        for(int i =0; i < ui->OrderList->count(); i++)
        {
            QListWidgetItem *w = ui->OrderList->item(i);
            items *it = dynamic_cast<items *>(ui->OrderList->itemWidget(w));
            if(i == 0)
            {
                QStringList lineList = ui->MenuName->text().split(" ");
                txt << lineList.value(0) << endl;
            }
            else if(i == 1)
            {
                txt << "Product Code,Product Name ,Unit KG,Price Per Unit (£),Price Per KG X" << endl;
            }
            else{
            txt << it->getItem("code") + "," + it->getItem("name") + ","+ it->getItem("unit")+ "," + it->getItem("price") << endl;
            }
        }
    }

}


void NewOrderWindow::on_Sort_currentIndexChanged(int index)
{



    if(index > 0) setMenus();

}
