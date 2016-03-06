#ifndef DOWNLOADSLOT_H
#define DOWNLOADSLOT_H

#include <QObject>
#include <QtNetwork>

class DownloadSlot : public QObject
{
    Q_OBJECT

public:
    DownloadSlot(QNetworkAccessManager *manager, QString outPath);
public slots:
    void downloadFinished(QNetworkReply *re);
private:
    QString str;
    QNetworkAccessManager *accessManager;
};

#endif // DOWNLOADSLOT_H
