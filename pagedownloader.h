#ifndef PAGEDOWNLOADER_H
#define PAGEDOWNLOADER_H

#include <QNetworkAccessManager>
#include <QObject>
#include "page.h"

class PageDownloader : public QObject
{
    Q_OBJECT
public:
    explicit PageDownloader( QObject* parent = nullptr );

    ~PageDownloader( );

signals:
    void started( );
    void finished( Page* page );

public slots:
    void finishDownload( QNetworkReply* reply );

public:
    void startDownload( Page* page );

private:
    QNetworkAccessManager* m_manager;
    Page* m_page;
};

#endif  // PAGEDOWNLOADER_H
