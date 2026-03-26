#include "exept.h"
#include "ui_exept.h"
#include <QMessageBox>

exept::exept(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::exept)
{
    ui->setupUi(this);
}

exept::~exept()
{
    delete ui;
}

QString exept::decryptText(const QString &text, const QString &key)
{
    if (key.isEmpty()) return text;

    QByteArray data = QByteArray::fromBase64(text.toUtf8());
    QByteArray k = key.toUtf8();

    for (int i = 0; i < data.size(); ++i) {
        data[i] = data[i] ^ k[i % k.size()];
    }

    return QString::fromUtf8(data);
}

void exept::on_pushButton_decrypt_clicked()
{
    QString crypted = ui->lineEdit_crypted->toPlainText();
    QString key = ui->lineEdit_key->text();

    if (crypted.isEmpty() || key.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введи и текст, и ключ, бля");
        return;
    }

    QString decrypted = decryptText(crypted, key);
    ui->lineEdit_3->setText(decrypted);
}

