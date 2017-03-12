#include "tag.hpp"

Tag::Tag()
{
    tags = new QFile();
    tags->setFileName("tags.json");
    tags->open(QIODevice::ReadWrite);
    QString data = tags->readAll();

    jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    objJson = jsonDoc.object();
}

QStringList Tag::getListTags() {
    return objJson.keys();
}

void Tag::addTag(QString tagName) {
    objJson.insert(tagName, QJsonValue());
    jsonDoc.setObject(objJson);
    QString strJson(jsonDoc.toJson(QJsonDocument::Compact));
    qDebug() << jsonDoc;
    if (tags->isOpen()) {
        tags->resize(0);
        QTextStream stream(tags);
        stream << strJson << endl;
    }
}

bool Tag::addElements(QStringList list, QString tagName) {
    if (!objJson.contains(tagName)) {
        return false;
    }

    for (int i = 0; i < list.size(); i++) {
        if (objJson[tagName].toArray().contains(list.at(i))) {
            list.removeAt(i);
        }
    }

    if (!objJson[tagName].isNull()) {
        QJsonArray array = objJson[tagName].toArray();
        while (array.size() != 0) {
            list.append(array.first().toString());
            array.removeFirst();
        }
    }

    QJsonArray arraypath = QJsonArray::fromStringList(list);
    objJson.insert(tagName, arraypath);
    jsonDoc.setObject(objJson);
    QString strJson(jsonDoc.toJson(QJsonDocument::Compact));

    if (tags->isOpen()) {
        tags->resize(0);
        QTextStream stream(tags);
        stream << strJson << endl;
    }
}

bool Tag::removeElement(QString tagName, QString element) {
    if (!objJson.contains(tagName)) {
        return false;
    }
    if (!objJson[tagName].isNull()) {
        QJsonArray array = objJson[tagName].toArray();
        for (int i = 0; i < array.size(); i++) {
            if (array.at(i) == element) {
                array.removeAt(i);
            }
        }
        objJson.insert(tagName, array);
        QString strJson(jsonDoc.toJson(QJsonDocument::Compact));

        if (tags->isOpen()) {
            tags->resize(0);
            QTextStream stream(tags);
            stream << strJson << endl;
        }
    }
}

QStringList Tag::getResultsResearch(QString tagName) {
    QStringList list;
    for (QJsonValue o : objJson[tagName].toArray()) {
        list.append(o.toString());
        qDebug() << o;
    }
    return list;
    // return QStringList(.toVariantList().toStdList());
}
