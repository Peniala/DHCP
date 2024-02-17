#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>
#include<QLabel>

namespace Ui {
class Information;
}

class Information : public QWidget
{
    Q_OBJECT

public:
    std::vector<std::string> perso;
    QLabel *perso_image;

    explicit Information(QWidget *parent = nullptr);
    ~Information();

    void setInformation(std::vector<std::string> personne, std::string image);

private slots:

    void on_one_2_clicked();

    void on_two_1_clicked();

    void on_one_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Information *ui;

};

#endif // INFORMATION_H
