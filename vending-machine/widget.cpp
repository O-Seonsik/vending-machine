#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int getMoney){
    money += getMoney;
    if(money >= 200) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(true);
    }else if (money >= 150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(false);
    }else if (money >= 100){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }else{
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }
    ui->lcdNumber->display(money);
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    using namespace std;
    string fiveHun = to_string(money / 500);
    string hun = to_string((money%500)/100);
    string fifty = to_string(((money%500)%100)/50);
    string ten = to_string((((money%500)%100)%50)/10);
    std::string message = "";
    message = "500 : " + fiveHun + "\n100 : " + hun + "\n50 : " + fifty + "\n10 : " + ten;
    const char *msg = message.c_str();
    money = 0;
    ui->lcdNumber->display(money);
    QMessageBox q;
    q.information(nullptr, "change", msg);
}
