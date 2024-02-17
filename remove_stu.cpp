#include "remove_stu.h"
#include "ui_remove_stu.h"

Remove_stu::Remove_stu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Remove_stu)
{
    ui->setupUi(this);
}

Remove_stu::~Remove_stu()
{
    delete ui;
}
