#include "items.h"
#include "ui_items.h"

items::items(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::items)
{
    ui->setupUi(this);
}

void items::setUnits(QString c, QString n, QString u, QString p)
{
    code = c;
    name = n;
    unit = u;
    price = p;
    ui->Name->setText(name);
    ui->Code->setText(code);
    ui->Unit->setText(unit);
    ui->Price->setText(price);
}
items::~items()
{
    delete ui;
}

void items::move(int type)
{
    ui->Price->move(ui->Price->x()+type, ui->Price->y());
    ui->Code->move(ui->Code->x()+type, ui->Code->y());


}
