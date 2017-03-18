#include "MainWindow.hpp"
#include <QApplication>
#include <iostream>
#include <string>
#include <fstream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "tag.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow fenetre;
    fenetre.show();

    return app.exec();
}
