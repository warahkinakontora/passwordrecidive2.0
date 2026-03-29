#ifndef ZXC_H
#define ZXC_H

#include "exept.h"
#include <QWidget>

namespace Ui {
class zxc;
}

class zxc : public QWidget
{
    Q_OBJECT

public:
    explicit zxc(QWidget *parent = nullptr);
    ~zxc();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::zxc *ui;
    exept *reist;

    QString encryptText(const QString &text, const QString &key);
};

#endif // ZXC_H
