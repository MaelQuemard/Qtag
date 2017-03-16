#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow()
{
    tag = new Tag();
    // zone centrale
    centralArea = new QWidget();

    // Adapater a la taille de l'écran
    screen = QGuiApplication::primaryScreen();
    screenGeometry = screen->geometry();
    centralArea->setBaseSize(screenGeometry.width(), screenGeometry.height()-50);
    centralArea->setMinimumSize(screenGeometry.width(), screenGeometry.height()-50);

    // Ajout dans la fenetre
    this->setCentralWidget(centralArea);

    tab = new QTabWidget(centralArea);
    tab->setMinimumSize(screenGeometry.width(), screenGeometry.height()-50);

    // différents onglets
    researchTab = new TabResearch(tag);
    associateTab = new TabAssociate(tag);

    /* -------- tab rechercher -------- */
    tab->addTab(associateTab,"Associer/Créer");
    tab->addTab(researchTab,"Rechercher/Consulter");

    /* ----- Barre de menu ----- */
    fileMenu = menuBar()->addMenu("&Fichier");

    exitAction = new QAction("&Quitter",this);
    fileMenu->addAction(exitAction);

    editionMenu = menuBar()->addMenu("&Edition");

    menuAffichage = menuBar()->addMenu("&Affichage");
    researchAction = new QAction("&Recherche/Consulter",this);
    menuAffichage->addAction(researchAction);
    associateAction = new QAction("&Consulter/Créer",this);
    menuAffichage->addAction(associateAction);

    MenuInfo = menuBar()->addMenu("&Info");


    /* ----- Connect changement d'onglet ----- */
    connect(tab, SIGNAL(currentChanged(int)), researchTab, SLOT(resetTab()));
    connect(tab, SIGNAL(currentChanged(int)), researchTab, SLOT(refreshListView()));
}
