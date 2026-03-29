#include "wex.h"
#include "ui_wex.h"
#include <QMessageBox>
#include "pass.h"
#include "sort.h"

wex::wex(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::wex)
{
    ui->setupUi(this);
}

wex::~wex()
{
    delete ui;
}

void wex::on_pushButton_clicked()
{
    QString name = ui->name->text();
    QString password = ui->password->text();

    if (name == "fuck" && password == "up") {
        pass *newWindow = new pass();
        newWindow->show(); //fuck up password
        this->close();
    } else {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Ты — это не твой логин. Но пароль ты точно проебал!");
        msgBox.setStyleSheet("QMessageBox { background-color: white; } QMessageBox QLabel { color: black; }");
        msgBox.exec();
        ui->name->clear();
        ui->password->clear();
        ui->name->setFocus();
    }
}


void wex::on_pushButton_2_clicked()
{
    hide();
    unix = new sort();
    unix->show();
}

