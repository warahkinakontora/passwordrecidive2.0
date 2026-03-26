#ifndef EXEPT_H
#define EXEPT_H

#include <QWidget>

namespace Ui {
class exept;
}

class exept : public QWidget
{
    Q_OBJECT

public:
    explicit exept(QWidget *parent = nullptr);
    ~exept();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_decrypt_clicked();

private:
    Ui::exept *ui;
     QString decryptText(const QString &text, const QString &key);
};

#endif // EXEPT_H
