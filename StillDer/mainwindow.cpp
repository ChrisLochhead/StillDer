#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->AddMenuScreen->hide();
    ui->Notification->hide();
    User myUser;
    myUser.setDetails("Alan", "password123");
    User admin;
    admin.setDetails("admin", "123");
    myUser.loadMenus();
    admin.loadMenus();


    users.push_back(myUser);
    users.push_back(admin);
}

MainWindow::~MainWindow()
{
    delete ui;
}

User MainWindow::getLoggedUser()
{
    return *loggedUser;
}

void MainWindow::on_SignIn_clicked()
{
   QString username = ui->User->text();
   QString password = ui->Pass->text();

   QVector<User>::iterator itt;

   for (itt = users.begin(); itt != users.end(); ++itt) {
     if(itt->getUser() == username && itt->getPass() == password)
     {
         loggedIn = true;
         ui->LoginPage->hide();
         ui->Notification->setStyleSheet("background-image: url(:/Images/Stillder UI/LoginMenu/LoggedIn.png);"
                                         "background-repeat: none;"
                                         "border: none;");
         loggedUser = itt;
     }
   }


if(loggedIn == false){
       ui->Notification->setStyleSheet("background-image: url(:/Images/Stillder UI/LoginMenu/IncorrectLogIn.png);"
                                       "background-repeat: none;"
                                       "border: none;");
}

    ui->Notification->show();
}

void MainWindow::on_AddMenu_clicked()
{
    if(loggedIn == true)
    ui->AddMenuScreen->show();

}

void MainWindow::on_Cancel_clicked()
{
    ui->AddMenuScreen->hide();
}

void MainWindow::on_Exit_clicked()
{
    this->close();
}

void MainWindow::on_Browse_clicked()
{
    QString menuName = QFileDialog::getOpenFileName(this, "Select the menu you wish to load.", "C://Users/chris/OneDrive/Documents/AlgorithmsProject/StillDer/Menus");
    QFile menuFile(menuName);

    if(!menuFile.open(QFile::ReadOnly | QFile::Text))
    {
        //find a way to change style sheet of warning message
        QMessageBox::warning(this, "Warning", "File could not be opened");
    }

    //display the selected menu file
    ui->File->setText(menuName);

    //let the menu know a valid file has been selected
    validFile = true;

    //set this file to the current file being handled
    menuFile.open(QIODevice::ReadOnly);
    currentfile = menuName;
}
void MainWindow::on_Load_clicked()
{
    // from here on will be its own function
    Menu m;

    //count the number of menu items by line
    int lineCount = 0;
    QString line[300];

    //reopen file
    QFile menuFile(currentfile);
    if(!menuFile.open(QFile::ReadOnly | QFile::Text))
    {
        //find a way to change style sheet of warning message
        QMessageBox::warning(this, "Warning", "File could not be opened");
    }
    while( !menuFile.atEnd())
    {

        QString menuName;

        QString name;
        QString code;
        QString unit;
        QString price;
        line[lineCount] = menuFile.readLine();

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
    qInfo() << m.getMenu().length();

    m.createTrees();
    m.getTree()->inOrderTraversal();
    QVector<MenuItem> a = m.getInOrderTree();
    Tree* mytree = m.getTree();

    loggedUser->setMenu(m);


    QDir dir("C:/Users/chris/OneDrive/Documents/AlgorithmsProject/StillDer/SavedMenus");
    QFile file(dir.path() + "/out.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text))
    {
        QFile f(currentfile);
        if(!f.open(QFile::ReadOnly | QFile::Text))
        {
            //find a way to change style sheet of warning message
            QMessageBox::warning(this, "Warning", "File could not be opened");
        }

        QTextStream txt(&file);
        while( !f.atEnd())
        {
            txt << f.readLine();
        }
    }

    //tidy up
    ui->File->setText(" ");
    validFile = false;

}

void MainWindow::on_NewOrder_clicked()
{
    if(loggedIn == true)
    {
        newOrder = new NewOrderWindow(this);
        setUser(0);
        newOrder->setMenus();
        newOrder->show();
    }
}

void MainWindow::on_OrderHistory_clicked()
{
    history = new OrderHistory(this);
    setUser(1);
    history->setOrders();
    history->show();
}
