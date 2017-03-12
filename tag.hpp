#ifndef TAG_HPP
#define TAG_HPP

#include <QFile>
#include <QString>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>

class Tag
{
    public:
        Tag();

        QStringList getListTags();
        void addTag(QString tagName);
        bool addElements(QStringList list, QString tagName);
        bool removeElement(QString tagName, QString element);
        QStringList getResultsResearch(QString tagName);

    private:
        QFile* tags;
        QJsonObject objJson;
        QJsonDocument jsonDoc;
};

#endif // TAG_HPP
