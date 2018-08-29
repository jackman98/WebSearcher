#include "pagedownloader.h"
#include <QNetworkReply>
#include <QNetworkRequest>

PageDownloader::PageDownloader( QObject* parent )
    : QObject( parent )
    , m_manager( nullptr )
{
}

PageDownloader::~PageDownloader( )
{
    qDebug( ) << __PRETTY_FUNCTION__;
}

void
PageDownloader::startDownload( Page* page )
{
    m_page = page;
    if ( m_page->isDownloaded( ) )
    {
        qDebug( ) << "Dow";
        return;
    }

    qDebug( ) << "Loading";

    m_manager = new QNetworkAccessManager( this );
    connect( m_manager, &QNetworkAccessManager::finished, this, &PageDownloader::finishDownload );

    emit started( );

    m_manager->get( QNetworkRequest( m_page->url( ) ) );
}

void
PageDownloader::finishDownload( QNetworkReply* reply )
{
    qDebug( ) << "Loading";

    if ( reply->error( ) )
    {
        qDebug( ) << "Error: " << reply->errorString( );
    }

    QString htmlText = QString::fromUtf8( reply->readAll( ) );
    m_page->setIsDownloaded( true );
    m_page->setHtmlText( htmlText );

    reply->deleteLater( );

    emit finished( m_page );
}
