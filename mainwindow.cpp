#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_ip.h"
#include "remove_stu.h"

#include "information.h"

#include <string>
#include <vector>
#include <fstream>
#include <QLabel>


std::vector<std::vector<std::string>> personne_L1={};
std::vector<std::string> img_L1={};
std::vector<QLabel*> image_L1={};
std::vector<std::vector<std::string>> personne_L2={};
std::vector<std::string> img_L2={};
std::vector<QLabel*> image_L2={};

//Pour diviser un string et avoir le information d'une étudiants
std::vector <std::string> split(std::string line,char sep){
    std::vector <std::string> elmt;

    size_t deb=0;
    size_t fin=0;

    for(int i=0;i<8;i++){
        fin=line.find(sep,deb);
        elmt.push_back(line.substr(deb,fin-deb));
        deb=fin+1;
    }

    return elmt;
}

//Pour avoir le chemin de chaque image des étudiants
std::vector <std::string> getPath(size_t nl, std::string filepath)
{
    std::vector<std::string> chemin{};
    for(size_t i=0;i<nl;i++)
    {
        chemin.push_back(filepath+std::to_string(i)+".jpg");
    }
    return chemin;
}

//Permettre d'avoir les information des étudiants
std::vector<std::vector<std::string>> getData(std::string filename)
{
    std::ifstream f1{filename};

    std::vector<std::vector<std::string>> tri;
    std::string s{};

    while(getline(f1 >> std::ws, s))
    {
        tri.push_back(split(s,','));
    }
    return tri;
}

void init_L1()
{

    //Pour avoir les informations avec chaque image des étudiants
    personne_L1 = getData("./../dhcp/image/L1/L1.csv");
    img_L1 = getPath(personne_L1.size(), "./../dhcp/image/L1/photo_L1/");

    for(size_t i=0;i<personne_L1.size();i++)
    {
        image_L1.push_back(new QLabel);
    }

    for (size_t i = 1; i < personne_L1.size(); i++)
    {
        //Affichage de l'image
        QLabel * image = new QLabel();
        QPixmap p(QString::fromStdString(img_L1[i]));
        p = p.scaled(100, 100, Qt::KeepAspectRatio);
        image->setPixmap(p);
        image->setFixedSize(100,100);
        image_L1[i]=image;
    }

}

void init_L2()
{

    //Pour avoir les informations avec chaque image des étudiants
    personne_L2 = getData("./../dhcp/image/L2/L2.csv");
    img_L2 = getPath(personne_L2.size(), "./../dhcp/image/L2/photo_L2/");

    for(size_t i=0;i<personne_L2.size();i++)
    {
        image_L2.push_back(new QLabel);
    }

    for (size_t i = 1; i < personne_L2.size(); i++)
    {
        //Affichage de l'image
        QLabel * image = new QLabel();
        QPixmap p(QString::fromStdString(img_L2[i]));
        p = p.scaled(100, 100, Qt::KeepAspectRatio);
        image->setPixmap(p);
        image->setFixedSize(100,100);
        image_L2[i]=image;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->add->setIcon(QIcon ("./../dhcp/image/plus.xcf"));
    ui->remove->setIcon(QIcon ("./../dhcp/image/trash-can.xcf"));
    ui->submit->setIcon(QIcon ("./../dhcp/image/sistrix.svg"));

    init_L1();
    init_L2();

    //Afficher les listes des L1 dans le prémier page
   affiche_L1("A");
   //Afficher les listes des L2 dans le deuxième page
   affiche_L2("A");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::affiche_information(std::vector<std::string> perso, std::string perso_image)
{
    Information *i = new Information;
    i->setInformation(perso, perso_image);
    i->show();
}

//Affichage de list des L1 dans le prémier page
void MainWindow::affiche_L1(QString search)
{
    QVBoxLayout *vertical = new QVBoxLayout;

    //init_L1();


    for (size_t i = 1; i < personne_L1.size(); i++)
    {
        if(VectorContains(personne_L1[i],search)){
            //Affiche la grade
            QLabel *label = new QLabel("L1 ");
            label->setStyleSheet("background-color : black; font: 11pt \"URW Gothic\";color : white; padding: 8px;");
            label->setFixedSize(40,100);

            //Les informations sur la personne
            QHBoxLayout * main_layout_inf = new QHBoxLayout ();
            QVBoxLayout * layout_inf = new QVBoxLayout ();
            //layout_inf->addWidget(new QLabel ("Numero: "+QString::fromStdString(personne_L1[i][0])) );
            layout_inf->addWidget(new QLabel ("Name : "+QString::fromStdString(personne_L1[i][1]).replace("_", " ")) );
    //        layout_inf->addWidget(new QLabel ("Mac-WIFI: "+QString::fromStdString(personne_L1[i][2])) );
    //        layout_inf->addWidget(new QLabel ("Mac-Eth: "+QString::fromStdString(personne_L1[i][3])) );
    //        layout_inf->addWidget(new QLabel ("Sérial: "+QString::fromStdString(personne_L1[i][4])) );
    //        layout_inf->addWidget(new QLabel ("PAN: "+QString::fromStdString(personne_L1[i][5])) );
    //        layout_inf->addWidget(new QLabel ("Etat: "+QString::fromStdString(personne_L1[i][6])) );
            layout_inf->addWidget(new QLabel ("IP : "+QString::fromStdString(personne_L1[i][7])) );
            //layout_inf->SetFixedSize(500, 100);

            //main_layout_inf->addWidget(image_L1[i]);
            layout_inf->setContentsMargins(15,5,0,5);
            layout_inf->setSpacing(0);

            main_layout_inf->addLayout(layout_inf);

            //Un petit boutton de modification
            QPushButton *button = new QPushButton(" More");

            button->setFixedSize(100,50);
            button->setStyleSheet("background-color: rgb(10,15,40); border-radius: 8px; border: 1px solid rgb(50,20,30);");
            button->setIcon(QIcon ("./../dhcp/image/circle-info.xcf"));

            connect(button, &QPushButton::clicked, this, [=](){
                std::vector<std::string> p = personne_L1[i];
                std::string im = img_L1[i];
                affiche_information(p, im);
            });

            QHBoxLayout *layout2 = new QHBoxLayout;
            layout2->addWidget(label);
            layout2->addLayout(main_layout_inf);
            layout2->addWidget(button);

            //Une petite ligne
            QFrame *line = new QFrame();
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);

            vertical->addLayout(layout2);
            vertical->addWidget(line);
        }

    }

    // Définir le widget principal du widget de défilement
    QWidget *widget = new QWidget;
    widget->setLayout(vertical);

    //On met dans le scroll area qui se situe dans la page 1
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(widget);
}

void MainWindow::affiche_L2(QString search)
{
    QVBoxLayout *vertical = new QVBoxLayout;

   // init_L2();
   bool exist = false;

    for (size_t i = 1; i < personne_L2.size(); i++)
    {

        if(VectorContains(personne_L2[i],search))
        {
            exist = true;
            //Affiche la grade
            QLabel *label = new QLabel("L2 ");
            label->setStyleSheet("background-color : black; font: 11pt \"URW Gothic\";color : white; padding: 8px;");
            label->setFixedSize(40,100);

            //Les informations sur la personne
            QHBoxLayout * main_layout_inf = new QHBoxLayout ();
            QVBoxLayout * layout_inf = new QVBoxLayout ();
    //        layout_inf->addWidget(new QLabel ("Numero: "+QString::fromStdString(personne_L2[i][0])) );
            layout_inf->addWidget(new QLabel ("Name : "+QString::fromStdString(personne_L2[i][1]).replace("_", " ")) );
    //        layout_inf->addWidget(new QLabel ("Mac-WIFI: "+QString::fromStdString(personne_L2[i][2])) );
    //        layout_inf->addWidget(new QLabel ("Mac-Eth: "+QString::fromStdString(personne_L2[i][3])) );
    //        layout_inf->addWidget(new QLabel ("Sérial: "+QString::fromStdString(personne_L2[i][4])) );
    //        layout_inf->addWidget(new QLabel ("PAN: "+QString::fromStdString(personne_L2[i][5])) );
    //        layout_inf->addWidget(new QLabel ("Etat: "+QString::fromStdString(personne_L2[i][6])) );
            layout_inf->addWidget(new QLabel ("IP : "+QString::fromStdString(personne_L2[i][7])) );
            //main_layout_inf->addWidget(image_L2[i]);

            layout_inf->setContentsMargins(15,5,0,5);
            layout_inf->setSpacing(0);

            main_layout_inf->addLayout(layout_inf);

            //Un petit boutton de modification
            QPushButton *button = new QPushButton(" More");
            button->setFixedSize(100,50);
            button->setIcon(QIcon ("./../dhcp/image/circle-info.xcf"));

            connect(button, &QPushButton::clicked, this, [=](){
                std::vector<std::string> p = personne_L2[i];
                std::string im = img_L2[i];
                affiche_information(p, im);
            });

            QHBoxLayout *layout2 = new QHBoxLayout;
            layout2->addWidget(label);
            layout2->addLayout(main_layout_inf);
            layout2->addWidget(button);

            //Une petite ligne
            QFrame *line = new QFrame();
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);

            vertical->addLayout(layout2);
            vertical->addWidget(line);
        }
    }

    if(!exist){
        QLabel *label = new QLabel("NO ONE");
        QWidget *widget = new QWidget;
        QHBoxLayout *layout2 = new QHBoxLayout;
        layout2->addWidget(label);
        widget->setLayout(layout2);
        ui->scrollArea_2->setWidgetResizable(true);
        ui->scrollArea_2->setWidget(widget);

    }
    else{
        // Définir le widget principal du widget de défilement
        QWidget *widget = new QWidget;
        widget->setLayout(vertical);


        //On met les listes des L2 dans le scroll area qui se situe dans la page 2
        ui->scrollArea_2->setWidgetResizable(true);
        ui->scrollArea_2->setWidget(widget);
    }
}

void MainWindow::on_add_clicked()
{
    Add_ip* a = new Add_ip();
    a->show();
}


//Pour changer dans la page 1
void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Pour changer dans la page 2
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_search_textChanged()
{
    QString a=ui->search->text();
    affiche_L1(a);
    affiche_L2(a);
    a.clear();
}

bool MainWindow::VectorContains(std::vector<std::string> personne,QString search){

    bool b=false;
    bool isNumber;
    //int integerValue;
    /*integerValue =*/ search.toInt(&isNumber);

    if(!isNumber){
        search = search.toLower();
        for(int j=1;j<8;j+=6){
            QString tmp = QString::fromStdString(personne[j]);
            tmp=tmp.toLower();
            if(tmp.contains(search)){
                b=true;
                break;
            }
        }
     }
    else{

        for(int j=1;j<8;j+=6){
            QString tmp = QString::fromStdString(personne[j]);

            if(tmp.contains(search)){
                b=true;
                break;
            }
        }
    }
    return b;
}

void MainWindow::on_submit_clicked()
{
    QString arg1 = ui->search->text();
    affiche_L1(arg1);
    affiche_L2(arg1);
}


void MainWindow::on_remove_clicked()
{
    Remove_stu* del = new Remove_stu();
    del->show();
}

