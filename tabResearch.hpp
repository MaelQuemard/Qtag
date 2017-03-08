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

class TabResearch : public QWidget
{
    Q_OBJECT
    public:
        TabResearch(QWidget *parent = 0);

    private:
        QListView* viewConsult;

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
        QPushButton* buttonHide;
        QHBoxLayout* layoutOnglet;

    signals:

    public slots:
        void affichageResearch();
        void resetTab();
};

#endif // TABRESEARCH_HPP
