#ifndef WEX_H
#define WEX_H

#include "sort.h"
#include <QWidget>

namespace Ui {
class wex;
}

class wex : public QWidget
{
    Q_OBJECT

public:
    explicit wex(QWidget *parent = nullptr);
    ~wex();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::wex *ui;
    sort *unix;
};

#endif // WEX_H
