#include "searchengine.h"
#include "searchworker.h"

SearchEngine::SearchEngine( DataProvider* dataProvider, QObject* parent )
    : QObject( parent )
    , mDataProvider( dataProvider )
{
    connect( dataProvider, &DataProvider::countOfThreadsChanged, this, [this]( int count ) {
        mThreadPool.setMaxThreadCount( count );
    } );
    connect( this, &SearchEngine::pagesChanged, this, &SearchEngine::procces );
}

void
SearchEngine::start( )
{
    mStartPage.setUrl( mDataProvider->startURl( ) );
    mStartPage.setSearchText( mDataProvider->searchText( ) );

    mPages.append( &mStartPage );
    emit pagesChanged( );
}

void
SearchEngine::procces( )
{
    if ( mPages.empty( ) )
    {
        return;
    }

    SearchWorker* worker = new SearchWorker( mPages.takeFirst( ) );

    connect( worker, &SearchWorker::finished, this, &SearchEngine::addPages );
    mThreadPool.start( worker );
}

void
SearchEngine::addPages( )
{
    Page* page = static_cast< SearchWorker* >( sender( ) )->page( );

    int findedWords = mDataProvider->countFindedWords( ) + page->countOfSearchText( );
    mDataProvider->setCountFindedWords( findedWords );
    mDataProvider->countFindedWordsChanged( findedWords );

    mPages.append( page->subpages );
    emit pagesChanged( );
}
