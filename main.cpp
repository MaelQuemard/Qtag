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

    Tag* t = new Tag();

    qDebug() << t->getListTags();
    QStringList* list = new QStringList("monPath");
    //t->addElements(*list, "machin");
    t->removeElement("machin", "monPath");
    qDebug() << t->getResultsResearch("machin");

    return app.exec();
}
