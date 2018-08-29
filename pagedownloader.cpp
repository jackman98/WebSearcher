#include "pagedownloader.h"
#include <QNetworkReply>
#include <QNetworkRequest>

PageDownloader::PageDownloader(QObject *parent) : QObject(parent)
{
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished, this, &PageDownloader::downloadFinished);
}

void PageDownloader::downloadPage(Page *page)
{
    m_downloadPage = page;
    if (page->isDownloaded()) {
        return;
    }

    m_manager->get(QNetworkRequest(m_downloadPage->url()));
}

void PageDownloader::downloadFinished(QNetworkReply *reply)
{
    if (reply->error()) {
        qDebug() << "Error: " << reply->errorString();
    }

    QString htmlText = QString::fromUtf8(reply->readAll());
    m_downloadPage->setIsDownloaded(true);
    m_downloadPage->setHtmlText(htmlText);
}
