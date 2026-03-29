#ifndef SORT_H
#define SORT_H
#include "pass.h"

#include <QWidget>

namespace Ui {
class sort;
}

class sort : public QWidget
{
    Q_OBJECT

public:
    explicit sort(QWidget *parent = nullptr);
    ~sort();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sort *ui;
    pass *veck;
};

#endif // SORT_H
