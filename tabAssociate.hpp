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

class TabAssociate : public QWidget
{
    Q_OBJECT
    public:
        TabAssociate(QWidget *parent = 0);

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
        void hideCreer();
        void createTag();
        void associateTag();
};

#endif // TABASSOCIATE_H
