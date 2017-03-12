#include "tabResearch.hpp"

TabResearch::TabResearch(QWidget *parent) : QWidget(parent)
{
    tag = new Tag();
    /* ----- Partie Consultation ----- */

    viewConsult = new QListView;
    listModel = new QStringListModel();
    listModel->setStringList(tag->getListTags());
    viewConsult->setModel(listModel);
    consultLayout = new QVBoxLayout;
    consultLayout->addWidget(viewConsult);
    consultWidget = new QWidget();
    consultWidget->setLayout(consultLayout);
    consultWidget->setFixedWidth(200);

    /* ----- Partie Recherche ----- */

        /* ----- Recherche ----- */

    saisieRecherche = new QLineEdit();
    saisieRecherche->setPlaceholderText("Votre recherche");
    buttonRechercher = new QPushButton("ok");

    widgetRechercher = new QWidget();

    layoutRecherche = new QHBoxLayout;
    layoutRecherche->addWidget(saisieRecherche);
    layoutRecherche->addWidget(buttonRechercher);
    widgetRechercher->setLayout(layoutRecherche);

        /* ----- Reponse -----*/
    int ligne = 5;

    saisieReponse = new QLineEdit();
    saisieReponse->setPlaceholderText("Votre recherche");
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


    /* ----- layout ----- */

    buttonHide = new QPushButton("<");
    layoutOnglet = new QHBoxLayout;
    layoutOnglet->addWidget(consultWidget);
    layoutOnglet->addWidget(buttonHide);
    layoutOnglet->addWidget(widgetReponse);
    layoutOnglet->addWidget(widgetRechercher);
    widgetReponse->setVisible(false);
    this->setLayout(layoutOnglet);



    /* ----- Connect ----- */

    connect(buttonResearch, SIGNAL(clicked()), this, SLOT(affichageResearch()));
    connect(buttonRechercher, SIGNAL(clicked()), this, SLOT(affichageResearch()));
    connect(buttonHide, SIGNAL(clicked()), this, SLOT(hideConsult()));
}

// SLOT
void TabResearch::affichageResearch(){
    //change de vue de Recherche vers Reponse
    widgetRechercher->setVisible(false);
    widgetReponse->setVisible(true);
    saisieReponse->setText(saisieRecherche->text());

    //TODO: Lancer la recherche
}

void TabResearch::resetTab() {
    widgetRechercher->setVisible(true);
    widgetReponse->setVisible(false);
    saisieRecherche->setText("");
}

void TabResearch::hideConsult() {
    if(!consultWidget->isVisible()){
        consultWidget->setVisible(true);
        buttonHide->setText("<");
    } else {
        consultWidget->setVisible(false);
        buttonHide->setText(">");
    }
}
