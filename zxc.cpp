#include "zxc.h"
#include "ui_zxc.h"
#include <QMessageBox>
#include <QString>
#include "exept.h"

zxc::zxc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::zxc)
{
    ui->setupUi(this);
}

zxc::~zxc()
{
    delete ui;
}

void zxc::on_pushButton_clicked()
{
    close();
}

void zxc::on_pushButton_2_clicked()
{

    QString text = ui->lineEdit->text();

    QString key = ui->keyEdit->toPlainText();

    if (text.isEmpty() || key.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Введи и текст, и ключ, бля");
        msgBox.setStyleSheet("QMessageBox { background-color: white; } QMessageBox QLabel { color: black; }");
        msgBox.exec();
        return;
    }

    QString encrypted = encryptText(text, key);


    ui->resultEdit->setText(encrypted);
}


QString zxc::encryptText(const QString &text, const QString &key)
{
    if (key.isEmpty()) {
        return text;
    }
    const int kLength = 16;
    QByteArray data = text.toUtf8();
    QByteArray k = key.toUtf8();

    for (int i = 0; i < data.size(); ++i) {
        data[i] = data[i] ^ k[i % k.size()];
    }

    return data.toBase64();
}

void zxc::on_pushButton_3_clicked()
{
    reist = new exept();
    reist->show();
}

