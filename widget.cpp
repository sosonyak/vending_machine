#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    buttonEnabled(money);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::changeMoney(int diff){
    money += diff;
    ui -> lcdNumber -> display(money);

    buttonEnabled(money);
}


void Widget::buttonEnabled(int money){
    ui->pb_coffee->setEnabled(money >= 100);
    ui->pb_tea->setEnabled(money >= 150);
    ui->pb_tang->setEnabled(money >= 200);
}


void Widget::on_pb_coin_10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb_coin_50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb_coin_100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb_coin_500_clicked()
{
    changeMoney(500);
}


void Widget::on_pb_coffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pb_tea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pb_tang_clicked()
{
    changeMoney(-200);
}

void Widget::on_pb_reset_clicked()
{
    QMessageBox mb;

    QString message = "[CHANGES]\n500: ";
    message.append(QString::number(money/500));
    money = money%500;
    message.append("\n100: ");
    message.append(QString::number(money/100));
    money = money%100;
    message.append("\n50: ");
    message.append(QString::number(money/50));
    money = money%50;
    message.append("\n10: ");
    message.append(QString::number(money/10));
    money = money%10;

    mb.information(nullptr, "CHANGED", message);

    changeMoney(0);
}
