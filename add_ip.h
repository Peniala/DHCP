#ifndef ADD_IP_H
#define ADD_IP_H

#include <QMainWindow>

namespace Ui {
class Add_ip;
}

class Add_ip : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_ip(QWidget *parent = nullptr);
    ~Add_ip();

private:
    Ui::Add_ip *ui;
};

#endif // ADD_IP_H
