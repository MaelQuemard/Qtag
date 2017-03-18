#ifndef TABASSOCIATE_H
#define TABASSOCIATE_H

#include <QWidget>
#include <QMdiArea>
#include <QTextEdit>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QIcon>
#include <QToolBar>
#include <QTableView>
#include <QStandardItem>
#include <QDockWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListView>
#include <QMessageBox>
#include <QDialog>
#include <QDirModel>
#include <QTreeView>
#include "tag.hpp"
#include <QStringListModel>
#include <QFileSystemModel>
#include "tabResearch.hpp"

/**
 * @brief Classe TabAssociate
 * @authors M. Quémard - S. Vuylsteke
 * Cette classe représente l'onglet "créer/associer"
 */
class TabAssociate : public QWidget
{
    Q_OBJECT
    public:

        /**
         * @brief Constructeur de la classe TabAssociate
         * @param tag, paramètre qui permet de recupérer les données
         * @param parent
         */
        TabAssociate(Tag* tag, QWidget *parent = 0);

    private:
        /* ----- Variables pour le formulaire de création de tag -----*/
        // Layout
        QVBoxLayout* formCreate;
        QWidget *widgetFormCreate;

        // Elements du formulaire
        QLabel* labelTag;
        QLineEdit* nameTag;
        QPushButton* buttonCreate;

        /* ----- Variables pour cacher le menu de gauche ----- */
        QHBoxLayout* layoutCreate;
        QPushButton* hideButton;

        /* ----- Varaibles pour l'onglet associer ----- */
        // Elements de l'onglet
        QPushButton* buttonValidate;
        QListView* listTag;
        QStringListModel* listModel;
        QDirModel* directoryModel;
        QTreeView* directoryView;

        //Layout
        QHBoxLayout* layoutAssociation;
        QHBoxLayout* layoutTab;
        QVBoxLayout* layoutDir;

        Tag* tag;

    signals:

    public slots:
        /**
         * @brief Slot hideCreer, permet de cacher le menu déroulant de gauche
         */
        void hideCreer();

        /**
         * @brief Slot createTag, permet de connecter le bouton de création de tag pour mettre à jour les données
         */
        void createTag();

        /**
         * @brief Slot associateTag, permet d'associer les élements selectionnés au tag choisi
         */
        void associateTag();
};

#endif // TABASSOCIATE_H
