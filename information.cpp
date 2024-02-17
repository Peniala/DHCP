#include "information.h"
#include "ui_information.h"

Information::Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
}

Information::~Information()
{
    delete ui;
}

void Information::setInformation(std::vector<std::string> personne, std::string image)
{
    //image->setFixedSize(300, 300);
    QPixmap p(QString::fromStdString(image));
    p = p.scaled(200, 200, Qt::KeepAspectRatio);
    ui->image->setPixmap(p);
    ui->label_3->setText(QString::fromStdString(personne[1]).replace("_", " "));
    ui->label_9->setText(QString::fromStdString(personne[0]));


    ui->label_19->setText(QString::fromStdString(personne[2]));
    ui->label_20->setText(QString::fromStdString(personne[3]));
    ui->label_21->setText(QString::fromStdString(personne[4]));
    ui->label_22->setText(QString::fromStdString(personne[5]));
    ui->label_24->setText(QString::fromStdString(personne[6]));
    ui->label_13->setText(QString::fromStdString(personne[1]).replace("_", " "));
}

void Information::on_one_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Information::on_two_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

