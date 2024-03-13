#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money = 0;
    void changeMoney(int diff);
    void buttonEnabled(int money);

private slots:
    void on_pb_coin_10_clicked();

    void on_pb_coin_50_clicked();

    void on_pb_coin_100_clicked();

    void on_pb_coin_500_clicked();

    void on_pb_coffee_clicked();

    void on_pb_tea_clicked();

    void on_pb_tang_clicked();

    void on_pb_reset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
