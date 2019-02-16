#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QVectorIterator>
#include <QDebug>
#include <QDialog>
#include <QDir>
#include "neworderwindow.h"
#include "orderhistory.h"
#include "user.h"
#include "menu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   User getUser()
   {
       return *loggedUser;
   }

   void setUser(int w)
   {
       if(w == 0){
       newOrder->setUser(loggedUser);
       }else{
         history->setUser(loggedUser);
       }
   }

private slots:
    void on_SignIn_clicked();

    void on_AddMenu_clicked();

    void on_Cancel_clicked();

    void on_Exit_clicked();

    void on_Browse_clicked();

    User getLoggedUser();

    void on_Load_clicked();

    void on_NewOrder_clicked();

    void on_OrderHistory_clicked();

private:
    Ui::MainWindow *ui;

    bool loggedIn = false;
    bool validFile = false;

    QVector<User> users;
    User* loggedUser;

    QString currentfile;

    NewOrderWindow* newOrder;
    OrderHistory* history;

};

#endif // MAINWINDOW_H
