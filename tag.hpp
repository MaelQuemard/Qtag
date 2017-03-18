#ifndef TAG_HPP
#define TAG_HPP

#include <QFile>
#include <QString>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>

/**
 * @brief Classe Tag
 * @authors M. Quémard - S. Vuylsteke
 * Classe Tag qui gère la persitence des données
 */
class Tag
{
    public:
        /**
         * @brief Constructeur de la classe Tag
         */
        Tag();

        /**
         * @brief Methode getListTags, permet de récuperer la liste des tags
         * @return La liste de tous tags
         */
        QStringList getListTags();

        /**
         * @brief Methode addTag, permet d'ajouter un tag dans le fichier JSON
         * @param tagName, nom du tag à ajouter
         */
        void addTag(QString tagName);

        /**
         * @brief Méthode addElements, permet d'ajouter plusieurs élements au tag choisis
         * @param list, liste des élements à ajouter
         * @param tagName, nom du tag auquel on souhaite ajouter des élements
         * @return Vrai ou faux si l'ajout est bien effectué
         */
        bool addElements(QStringList list, QString tagName);

        /**
         * @brief Méthode removeElement, permet de supprimer un élement du fichier JSON
         * @param tagName, Nom du tag auquel nous allons enlever des élements
         * @param element, Element que l'on souhaite supprimer
         * @return Vrai ou faux si la suppression est bien effectué
         */
        bool removeElement(QString tagName, QString element);

        /**
         * @brief Méthode getResultsResearch, permet de récuperer les élements associé au tag rechercher
         * @param tagName, nom du tag recherché
         * @return La liste des élements correspondant au tag
         */
        QStringList getResultsResearch(QString tagName);

        /**
         * @brief Méthode getResultsResearchUnion, permet de récuperer l'union des résultats de plusieurs tags
         * @param tagsName, Noms des tags recherché
         * @return La liste des élements correspondants au différents tags
         */
        QStringList getResultsResearchUnion(QStringList tagsName);

    private:
        QFile* tags;
        QJsonObject objJson;
        QJsonDocument jsonDoc;
};

#endif // TAG_HPP
