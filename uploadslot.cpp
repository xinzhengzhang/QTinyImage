#include "uploadslot.h"
#include <QtNetwork>
#include "downloadslot.h"

UploadSlot::UploadSlot(QNetworkAccessManager *manager, int row, QString outPath):QObject()
{
    str = outPath;
    accessManager = manager;
    this->row = row;
}

void UploadSlot::replyFinished(QNetworkReply *re)
{
    QByteArray data = re->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data);
    QJsonObject jsonObject = jsonResponse.object();
    QJsonObject outputObject = jsonObject["output"].toObject();
    QString url = outputObject["url"].toString();
    size = outputObject["size"].toInt();
//    qDebug(data);
    if (url.length() == 0) {
        emit transferDone(row, 0, 0, QString(jsonResponse.toJson(QJsonDocument::Compact)));
        return;
    }
    QUrl downloadUrl(url);
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    DownloadSlot *slot = new DownloadSlot(manager, str);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            slot, SLOT(downloadFinished(QNetworkReply*)));
    QNetworkRequest *req = new QNetworkRequest(downloadUrl);
    manager->get(*req);
//    delete(accessManager);
}

void UploadSlot::downloadFinished(QNetworkReply *reply)
{
    emit transferDone(row, 1, size, str);
    delete(this);
}

