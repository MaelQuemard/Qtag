#include "tabResearch.hpp"

TabResearch::TabResearch(QWidget *parent) : QWidget(parent)
{

    /* ----- Partie Consultation ----- */

    viewConsult = new QListView;

    /* ----- Partie Recherche ----- */

        /* ----- Recherche ----- */

    saisieRecherche = new QLineEdit("votre recherche");
    buttonRechercher = new QPushButton("ok");

    widgetRechercher = new QWidget();

    layoutRecherche = new QHBoxLayout;
    layoutRecherche->addWidget(saisieRecherche);
    layoutRecherche->addWidget(buttonRechercher);
    widgetRechercher->setLayout(layoutRecherche);

        /* ----- Reponse -----*/
    int ligne = 5;

    saisieReponse = new QLineEdit("votre recherche");
    saisieReponse->setMaximumWidth(300);
    buttonResearch = new QPushButton("ok");

    layoutSaisie = new QHBoxLayout;
    layoutSaisie->addWidget(saisieReponse);
    layoutSaisie->addWidget(buttonResearch);

    modele = new QStandardItemModel(ligne,3);

    view = new QTableView;
    view->setModel(modele);

    widgetReponse = new QWidget();

    layoutReponse = new QVBoxLayout;
    layoutReponse->addLayout(layoutSaisie);
    layoutReponse->addWidget(view);
    widgetReponse->setLayout(layoutReponse);
    //widgetReponse->setVisible(true);


    /* ----- layout ----- */

    buttonHide = new QPushButton("<");
    layoutOnglet = new QHBoxLayout;
    layoutOnglet->addWidget(viewConsult);
    layoutOnglet->addWidget(buttonHide);
    layoutOnglet->addWidget(widgetReponse);
    layoutOnglet->addWidget(widgetRechercher);
    widgetReponse->setVisible(false);
    this->setLayout(layoutOnglet);



    /* ----- Connect ----- */

    connect(buttonResearch, SIGNAL(clicked()), this, SLOT(affichageResearch()));
    connect(buttonRechercher, SIGNAL(clicked()), this, SLOT(affichageResearch()));
}

// SLOT
void TabResearch::affichageResearch(){
    //change de vue de Recherche vers Reponse
    widgetRechercher->setVisible(false);
    widgetReponse->setVisible(true);

    //TODO: Lancer la recherche
}

void TabResearch::resetTab() {
    widgetRechercher->setVisible(true);
    widgetReponse->setVisible(false);
}
