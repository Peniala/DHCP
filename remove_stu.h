#ifndef REMOVE_STU_H
#define REMOVE_STU_H

#include <QWidget>

namespace Ui {
class Remove_stu;
}

class Remove_stu : public QWidget
{
    Q_OBJECT

public:
    explicit Remove_stu(QWidget *parent = nullptr);
    ~Remove_stu();

private:
    Ui::Remove_stu *ui;
};

#endif // REMOVE_STU_H
