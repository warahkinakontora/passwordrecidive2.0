#ifndef PASS_H
#define PASS_H
#include "zxc.h"
#include <QWidget>

namespace Ui {
class pass;
}

class pass : public QWidget
{
    Q_OBJECT

public:
    explicit pass(QWidget *parent = nullptr);
    ~pass();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::pass *ui;
    zxc *pps;
};
void tmpFunc();
#endif // PASS_H
