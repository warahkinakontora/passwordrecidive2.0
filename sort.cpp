#include "sort.h"
#include "ui_sort.h"
#include <QMessageBox>
#include <QFile>
#include "pass.h"

sort::sort(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sort)
{
    ui->setupUi(this);
}

sort::~sort()
{
    delete ui;
}

void sort::on_pushButton_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Заполни оба поля, бля");
        msgBox.setStyleSheet("QMessageBox { background-color: white; } QMessageBox QLabel { color: black; }");
        msgBox.exec();
        return;
    }

    QFile file("users.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << login << ":" << password << "\n";
        file.close();
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Успех");
        msgBox.setText("Регистрация прошла успешно, ебать");
        msgBox.setStyleSheet("QMessageBox { background-color: white; } QMessageBox QLabel { color: black; }");
        msgBox.exec();

        veck = new pass();
        veck->show();

        this->close();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные. Проверь права на запись.");
    }
}


