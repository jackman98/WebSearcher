#ifndef PAGEDOWNLOADER_H
#define PAGEDOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include "page.h"

class PageDownloader : public QObject
{
    Q_OBJECT
public:
    explicit PageDownloader(QObject *parent = nullptr);

signals:

public slots:
    void downloadFinished(QNetworkReply *reply);

public:
    void downloadPage(Page *page);

private:
    QNetworkAccessManager *m_manager;
    Page *m_downloadPage;
};

#endif // PAGEDOWNLOADER_H
