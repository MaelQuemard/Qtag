#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

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
#include <QDirModel>
#include <QDesktopWidget>
#include <QScreen>
#include <QTreeView>
#include "tabAssociate.hpp"
#include "tabResearch.hpp"
#include "tag.hpp"

/**
 * @brief Classe MainWindow
 * @authors M. Quémard - S. Vuylsteke
 * Cette classe regroupe tous les elements pour l'application
 */
class MainWindow : public QMainWindow {

    Q_OBJECT

    private:

    public:
        MainWindow();

    private:
        Tag* tag;
        /* ----- Variables de la fenetre ----- */
        QWidget* centralArea;
        QScreen *screen;
        QRect screenGeometry;

        /* ---- Variables pour les onglets ----- */
        QTabWidget* tab;
        QWidget* researchTab;
        QWidget* associateTab;

        /* ---- Variables pour la barre de menu ---- */
        // Menu fichier
        QMenu* fileMenu;
        QAction* addAction;
        QAction* saveAction;
        QAction* importAction;
        QAction* exitAction;

        // Menu edition
        QMenu* editionMenu;

        // Menu Affichage
        QMenu* menuAffichage;
        QAction* researchAction;
        QAction* associateAction;
        QMenu* MenuInfo;

    public slots:

    signals:
};

#endif // MAINWINDOW_HPP
