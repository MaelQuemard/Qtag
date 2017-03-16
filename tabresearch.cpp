#include "tabResearch.hpp"

TabResearch::TabResearch(Tag* tag, QWidget *parent) : QWidget(parent)
{
    this->tag = tag;
    /* ----- Partie Consultation ----- */

    viewConsult = new QListView;
    viewConsult->setEditTriggers(QAbstractItemView::NoEditTriggers);
    viewConsult->setSelectionMode(QAbstractItemView::ExtendedSelection);
    listModel = new QStringListModel();
    listModel->setStringList(tag->getListTags());
    viewConsult->setModel(listModel);
    rechercheRapide = new QPushButton("Recherche rapide");
    consultLayout = new QVBoxLayout;
    consultLayout->addWidget(viewConsult);
    consultLayout->addWidget(rechercheRapide);
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

    saisieReponse = new QLineEdit();
    saisieReponse->setPlaceholderText("Votre recherche");
    saisieReponse->setMaximumWidth(200);
    buttonResearch = new QPushButton("ok");

    layoutSaisie = new QHBoxLayout;
    layoutSaisie->addWidget(saisieReponse);
    layoutSaisie->addWidget(buttonResearch);

    modele = new QStandardItemModel(this);

    view = new QTableView();
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setModel(modele);

    widgetReponse = new QWidget();

    dislinkButton = new QPushButton("Dissocier");
    dislinkButton->setMaximumWidth(200);

    layoutReponse = new QVBoxLayout;
    layoutReponse->addLayout(layoutSaisie);
    layoutReponse->addWidget(view);
    layoutReponse->addWidget(dislinkButton);
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

    connect(buttonResearch, SIGNAL(clicked()), this, SLOT(affichageResponse()));
    connect(buttonRechercher, SIGNAL(clicked()), this, SLOT(affichageResearch()));
    connect(buttonHide, SIGNAL(clicked()), this, SLOT(hideConsult()));
    connect(rechercheRapide,SIGNAL(clicked()),this, SLOT(rechercheDirect()));
    connect(view, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(openFile(QModelIndex)));
    connect(dislinkButton, SIGNAL(clicked()), this, SLOT(dislink()));
}

// SLOT
void TabResearch::affichageResearch() {
    //change de vue de Recherche vers Reponse
    widgetRechercher->setVisible(false);
    widgetReponse->setVisible(true);
    saisieReponse->setText(saisieRecherche->text());

    //TODO: Lancer la recherche

    QStringList result = this->tag->getResultsResearch(saisieRecherche->text());
    this->modele->setColumnCount(1);
    this->modele->setRowCount(result.size());

    int nb_way=1;
    for (QString r : result) {
       // this->modele->appendRow(new QStandardItem(r));
        this->modele->setData(this->modele->index(nb_way-1, 0), r);
        nb_way++;
    }
    this->view->show();
    this->view->setColumnWidth(0, this->view->width());

}

void TabResearch::affichageResponse() {
    //change de vue de Recherche vers Reponse
    widgetRechercher->setVisible(false);
    widgetReponse->setVisible(true);
    saisieReponse->setText(saisieReponse->text());

    //TODO: Lancer la recherche

    QStringList result = this->tag->getResultsResearch(saisieReponse->text());
    this->modele->setColumnCount(1);
    this->modele->setRowCount(result.size());

    int nb_way=1;
    for (QString r : result) {
        this->modele->setData(this->modele->index(nb_way-1, 0), r);
        nb_way++;
    }
    this->view->show();
    this->view->setColumnWidth(0,this->width()*2);

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

void TabResearch::rechercheDirect() {
    QList<QModelIndex> mi = viewConsult->selectionModel()->selectedIndexes();
    if (mi.length() == 1) {
        for (QModelIndex m : mi) {
            QStringList result = this->tag->getResultsResearch(listModel->data(m, Qt::DisplayRole).toString());
            this->modele->setColumnCount(1);
            this->modele->setRowCount(result.size());

            int nb_way=1;
            for (QString r : result) {
                this->modele->setData(this->modele->index(nb_way-1, 0), r);
                nb_way++;
            }
        }

        this->view->show();
        this->view->setColumnWidth(0,this->width()*2);
    } else {
        QStringList tagsName;
        for (QModelIndex m : mi) {
            tagsName.append(listModel->data(m, Qt::DisplayRole).toString());
        }
        QStringList result = this->tag->getResultsResearchUnion(tagsName);
        this->modele->setColumnCount(1);
        this->modele->setRowCount(result.size());

        int nb_way=1;
        for (QString r : result) {
            this->modele->setData(this->modele->index(nb_way-1, 0), r);
            nb_way++;
        }
    }
    this->view->show();
    this->view->setColumnWidth(0,this->width()*2);

    //change de vue de Recherche vers Reponse
    widgetRechercher->setVisible(false);
    widgetReponse->setVisible(true);
    saisieReponse->setText(saisieRecherche->text());
}

void TabResearch::refreshListView() {
    //qDebug() << tag->getListTags();
    this->listModel->setStringList(this->tag->getListTags());
    this->viewConsult->setModel(this->listModel);
    //this->viewConsult->show();
}

void TabResearch::openFile(QModelIndex index) {
    //this->menuWay->setVisible(false);
    //QModelIndex index = this->view->currentIndex();
    QString path = index.data().toString();

    if(!QDesktopServices::openUrl(QUrl::fromLocalFile(path)))
    {
        QMessageBox::critical(this,"Erreur d'ouverture", "Il est impossible d'ouvrir le fichier/dossier : "+path+".");
    }
}

void TabResearch::removeElement() {
    qDebug() << "Here";
}

void TabResearch::dislink() {
    if (saisieReponse->text() != "") {
        for (QModelIndex it : view->selectionModel()->selectedIndexes()) {
            this->tag->removeElement(saisieReponse->text(), it.data().toString());
        }
    } else {
        for (QModelIndex tag : viewConsult->selectionModel()->selectedIndexes()) {
            for (QModelIndex it : view->selectionModel()->selectedIndexes()) {
                this->tag->removeElement(tag.data().toString(), it.data().toString());
            }
        }
    }
}
