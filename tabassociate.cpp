#include "tabAssociate.hpp"

TabAssociate::TabAssociate(Tag* tag, QWidget *parent) : QWidget(parent)
{
    /* ----- Instance tag pour la persistence ----- */
    this->tag = tag;

    /* -------- onglet associer -------- */
    //Formulaire de création de nouveau tag
    labelTag = new QLabel;
    labelTag->setText("Ajouter un nouveau Tag");
    nameTag = new QLineEdit();
    nameTag->setPlaceholderText("Nom du nouveau tag");
    buttonCreate = new QPushButton("Creer");
    formCreate = new QVBoxLayout;
    formCreate->addWidget(labelTag);
    formCreate->addWidget(nameTag);
    formCreate->addWidget(buttonCreate);
    widgetFormCreate = new QWidget();
    widgetFormCreate->setLayout(formCreate);
    widgetFormCreate->setFixedWidth(200);

    // hide layout
    layoutCreate = new QHBoxLayout;
    hideButton = new QPushButton("<");
    hideButton->setFixedSize(15, 40);
    layoutCreate->addWidget(widgetFormCreate);
    layoutCreate->addWidget(hideButton);


    // Layout Associer

    //QTableView -- ajouter la liste des tags.
    listTag = new QListView();
    listTag->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listTag->setSelectionMode(QAbstractItemView::ExtendedSelection);
    listTag->setFixedWidth(200);
    listModel = new QStringListModel();
    listModel->setStringList(tag->getListTags());
    listTag->setModel(listModel);

    //DirectoryView
    directoryModel = new QDirModel;
 //   directoryModel->setRootPath(QDir::homePath());
    directoryView = new QTreeView();
    directoryView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    directoryView->setModel(directoryModel);

    // Button valider
    buttonValidate = new QPushButton("Valider");

    layoutDir = new QVBoxLayout;
    layoutDir->addWidget(directoryView);
    layoutDir->addWidget(buttonValidate);

    layoutAssociation = new QHBoxLayout;
    layoutAssociation->addWidget(listTag);
    layoutAssociation->addLayout(layoutDir);

    layoutTab = new QHBoxLayout;
    layoutTab->addLayout(layoutCreate);
    layoutTab->addLayout(layoutAssociation);

    this->setLayout(layoutTab);

    connect(hideButton, SIGNAL(clicked()), this, SLOT(hideCreer()));
    connect(buttonCreate, SIGNAL(clicked()), this, SLOT(createTag()));
    connect(buttonValidate, SIGNAL(clicked()), this, SLOT(associateTag()));
}

// SLOTS
void TabAssociate::hideCreer(){
    if(!widgetFormCreate->isVisible()){
        widgetFormCreate->setVisible(true);
        hideButton->setText("<");
    } else {
        widgetFormCreate->setVisible(false);
        hideButton->setText(">");
    }
}

void TabAssociate::createTag() {
    tag->addTag(nameTag->text());
    listModel->setStringList(tag->getListTags());
}

void TabAssociate::associateTag() {
    int row = -1;
    QStringList list;
    for (QModelIndex mi : directoryView->selectionModel()->selectedIndexes()) {
        if (mi.row() != row) {
            list.append(directoryModel->filePath(mi));
            row = mi.row();
        }
    }
    if(tag->addElements(list, listTag->currentIndex().data(Qt::DisplayRole).toString())) {
        QMessageBox::about(this, tr("Qtag"), tr("Vos dossiers/fichiers ont été associés avec succès") );
    }
}
