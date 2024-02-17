#include "add_ip.h"
#include "ui_add_ip.h"

Add_ip::Add_ip(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add_ip)
{
    ui->setupUi(this);
}

Add_ip::~Add_ip()
{
    delete ui;
}
