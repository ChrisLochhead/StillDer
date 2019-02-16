#ifndef ITEMS_H
#define ITEMS_H

#include <QWidget>

namespace Ui {
class items;
}

class items : public QWidget
{
    Q_OBJECT

public:
    explicit items(QWidget *parent = nullptr);
    ~items();
    void setUnits(QString c, QString n, QString u, QString p);
    QString getItem(QString i)
    {
        if(i == "code")
        {
            return code;
        }

        if(i == "name")
        {
            return name;
        }

        if(i == "price")
        {
            return price;
        }

        if(i == "unit")
        {
            return unit;
        }
        return "could not find";

    }


    void move(int type);

private:
    Ui::items *ui;
    QString code;
    QString name;
    QString unit;
    QString price;
};

#endif // ITEMS_H
