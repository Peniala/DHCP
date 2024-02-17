#include "mainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleFile("./../dhcp/dhcp.css");
    styleFile.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(styleFile.readAll());
    a.setStyleSheet(stylesheet);
    MainWindow w;
    w.show();
    return a.exec();
}
