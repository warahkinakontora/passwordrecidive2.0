#ifndef SEXINSTRUKOR_H
#define SEXINSTRUKOR_H
#include "wex.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class sexinstrukor;
}
QT_END_NAMESPACE

class sexinstrukor : public QMainWindow
{
    Q_OBJECT

public:
    sexinstrukor(QWidget *parent = nullptr);
    ~sexinstrukor();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sexinstrukor *ui;
    wex *sex;

};
#endif // SEXINSTRUKOR_H
