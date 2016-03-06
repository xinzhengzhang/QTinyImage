#ifndef UPLOADSLOT_H
#define UPLOADSLOT_H

#include <QObject>
#include <QtNetwork>

class UploadSlot: public QObject
{
    Q_OBJECT

public:
    UploadSlot(QNetworkAccessManager *manager, int row,QString outPath);
public slots:
    void replyFinished(QNetworkReply *re);
    void downloadFinished(QNetworkReply *re);

signals:
    void transferDone(int row, int status, int size, QString path);

private:
    QString str;
    int size;
    int row;
    QNetworkAccessManager *accessManager;
};

#endif // UPLOADSLOT_H
