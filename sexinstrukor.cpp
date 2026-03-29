#include "sexinstrukor.h"
#include "./ui_sexinstrukor.h"
#include <QWidget>

sexinstrukor::sexinstrukor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sexinstrukor)
{
    ui->setupUi(this);
}

sexinstrukor::~sexinstrukor()
{
    delete ui;
}

void sexinstrukor::on_pushButton_clicked()
{
    hide();
    sex = new wex();
    sex->show();
}

