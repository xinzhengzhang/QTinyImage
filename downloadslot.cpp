#include "downloadslot.h"
#include <QtNetwork>

DownloadSlot::DownloadSlot(QNetworkAccessManager *accessManager, QString outPath):QObject()
{
    str = outPath;
    this->accessManager = accessManager;
}

void DownloadSlot::downloadFinished(QNetworkReply *reply)
{
    qDebug()<<"Download success"+str;
    QByteArray data = reply->readAll();
    QFile outFile(str);
    if (!outFile.open(QIODevice::WriteOnly)){
          qDebug() << "QFile Error: File open fail";
    } else { qDebug() << "File found, proceed as planned"; }
    outFile.write(data);
    outFile.close();
    delete(accessManager);
    delete(this);
}
