#include "searchworker.h"
#include <QEventLoop>

SearchWorker::SearchWorker( Page* page, QObject* parent )
    : QObject( parent )
    , mPage( page )
{
}

SearchWorker::~SearchWorker( )
{
    mPage->deleteLater( );
}

void
SearchWorker::run( )
{
    PageDownloader pageDownloader;
    PageParser pageParser;
    connect( &pageDownloader, &PageDownloader::finished, &pageParser, &PageParser::startParse );
    connect( &pageParser, &PageParser::finished, this, &SearchWorker::finished );

    QEventLoop loop;

    connect( this, &SearchWorker::finished, &loop, &QEventLoop::quit );

    pageDownloader.startDownload( mPage );

    qDebug( ) << "Loading";
    loop.exec( );
    qDebug( ) << "Worker finished";
}

Page*
SearchWorker::page( ) const
{
    return mPage;
}

// void
// SearchWorker::finish( )
//{
//    emit finished( );
//}
