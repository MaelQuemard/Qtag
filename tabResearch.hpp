#ifndef TABRESEARCH_HPP
#define TABRESEARCH_HPP

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>
#include <QListView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringListModel>
#include <QDesktopServices>
#include <QMessageBox>
#include "tag.hpp"

/**
 * @brief Classe TabResearch
 * @authors M. Quémard - S. Vuylsteke
 * Classe qui représente l'onglet "rechercher/consulter"
 */
class TabResearch : public QWidget
{
    Q_OBJECT
    public:

        /**
         * @brief Constructeur de la classe TabResearch
         * @param tag, paramètre qui permet de recupérer les données
         * @param parent
         */
        TabResearch(Tag* tag, QWidget *parent = 0);

    private:
        Tag* tag;

        QListView* viewConsult;
        QStringListModel* listModel;
        QPushButton* rechercheRapide;
        QVBoxLayout* consultLayout;
        QWidget* consultWidget;

        QLineEdit* saisieRecherche;
        QPushButton* buttonRechercher;

        QWidget* widgetRechercher;
        QHBoxLayout* layoutRecherche;

        QLineEdit* saisieReponse;
        QPushButton* buttonResearch;

        QHBoxLayout* layoutSaisie;

        QStandardItemModel* modele;

        QTableView* view;
        QWidget* widgetReponse;
        QVBoxLayout* layoutReponse;
        QPushButton* dislinkButton;
        QPushButton* buttonHide;
        QHBoxLayout* layoutOnglet;

    signals:

    public slots:

        /**
         * @brief Slot affichageResearch, permet d'afficher le résultat de la recherche écrit dans le champs de recherche de la première page
         */
        void affichageResearch();

        /**
         * @brief Slot affichageResponse, permet d'afficher le résultat de la recherche écrit dans le champs de recherche de la page de réponse
         */
        void affichageResponse();

        /**
         * @brief Slot resetTab, permet de réinitialiser l'onglet "rechercher/consulter" lorsque l'on change d'onglet
         */
        void resetTab();

        /**
         * @brief Slot hideConsult, permet de cacher le menu déroulant de gauche
         */
        void hideConsult();

        /**
         * @brief Slot rechercheDirect, permet de rechercher selon les tags sélectionnés dans la barre de consultation de tags
         */
        void rechercheDirect();

        /**
         * @brief Slot refreshListView, permet de rafraichir la liste des tags si on reviens du l'onglet "créer/associer"
         */
        void refreshListView();

        /**
         * @brief Slot openFile, permet d'ouvrir le fichier/dossier qui à été double-cliqué avec l'outil adapté (explorateur de fichier, visionneuse... )
         * @param index, permet de connaître l'élement qui doit être ouvert
         */
        void openFile(QModelIndex index);

        /**
         * @brief Slot dislink, permet de dissocier les élements sélectionnés du tag concerné
         */
        void dislink();
};

#endif // TABRESEARCH_HPP
