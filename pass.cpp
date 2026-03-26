#include "pass.h"
#include "ui_pass.h"
#include <random>
#include <QString>
#include "zxc.h"
#include <QDebug>

pass::pass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pass)
{
    ui->setupUi(this);

}

pass::~pass()
{
    delete ui;
}


QString generatepassword() {
    const QString chars = "abcdefghijklmnopqrstuvwxyz"
                          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                          "0123456789"
                          "!@#$%^&*()-+=[\\]{};:,.<>?";

    const int passwordLength = 16;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, chars.length() - 1);

    QString password;
    for (int i = 0; i < passwordLength; ++i) {
        int index = distribution(generator);
        password.append(chars.at(index));
    }

    return password;
}

void pass::on_pushButton_clicked()
{
    QString newpassword = generatepassword();
    ui->textEdit->setText(newpassword);
}

void pass::on_pushButton_3_clicked()
{
    close();
}

void pass::on_pushButton_2_clicked()
{
    pps = new zxc();
    pps->show();
}
