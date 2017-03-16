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

class TabResearch : public QWidget
{
    Q_OBJECT
    public:
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
        void affichageResearch();
        void affichageResponse();
        void resetTab();
        void hideConsult();
        void rechercheDirect();
        void refreshListView();
        void openFile(QModelIndex index);
        void removeElement();
        void dislink();
};

#endif // TABRESEARCH_HPP
