#include "remove_form.h"
#include "ui_remove_form.h"

Remove_form::Remove_form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Remove_form)
{
    ui->setupUi(this);
}

Remove_form::~Remove_form()
{
    delete ui;
}
