#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>

#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void add_information();

private slots:
    void on_add_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void affiche_information(std::vector<std::string> perso, std::string perso_image);


    void on_search_textChanged();
    bool VectorContains(std::vector<std::string> personne,QString search);



    void on_submit_clicked();

private:
    Ui::MainWindow *ui;


    void affiche_L2(QString search);
    void affiche_L1(QString search);

//    void affiche_L1();
//    void affiche_L2();
};
#endif // MAINWINDOW_H
