#ifndef REMOVE_FORM_H
#define REMOVE_FORM_H

#include <QWidget>

namespace Ui {
class Remove_form;
}

class Remove_form : public QWidget
{
    Q_OBJECT

public:
    explicit Remove_form(QWidget *parent = nullptr);
    ~Remove_form();

private:
    Ui::Remove_form *ui;
};

#endif // REMOVE_FORM_H
