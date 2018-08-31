#include "dataprovider.h"
#include <QDebug>

DataProvider::DataProvider( QObject* parent )
    : QObject( parent )
{
}

QUrl
DataProvider::startURl( ) const
{
    return m_startURl;
}

int
DataProvider::countOfThreads( ) const
{
    return m_countOfThreads;
}

QString
DataProvider::searchText( ) const
{
    return m_searchText;
}

int
DataProvider::maxCountScanningURL( ) const
{
    return m_maxCountScanningURL;
}

int
DataProvider::countFindedWords( ) const
{
    return m_countFindedWords;
}

void
DataProvider::setStartURl( QUrl startURl )
{
    if ( m_startURl == startURl )
        return;

    m_startURl = startURl;
    emit startURlChanged( m_startURl );
}

// void
// DataProvider::setStartURl( QString startURl )
//{
//    if ( m_startURl.toString( ) == startURl )
//        return;

//    m_startURl = QUrl( startURl );
//    emit startURlChanged( m_startURl );
//}

void
DataProvider::setCountOfThreads( int countOfThreads )
{
    if ( m_countOfThreads == countOfThreads )
        return;

    m_countOfThreads = countOfThreads;
    emit countOfThreadsChanged( m_countOfThreads );
}

void
DataProvider::setSearchText( QString searchText )
{
    if ( m_searchText == searchText )
        return;

    m_searchText = searchText;
    emit searchTextChanged( m_searchText );
}

void
DataProvider::setMaxCountScanningURL( int maxCountScanningURL )
{
    if ( m_maxCountScanningURL == maxCountScanningURL )
        return;

    m_maxCountScanningURL = maxCountScanningURL;
    emit maxCountScanningURLChanged( m_maxCountScanningURL );
}

void
DataProvider::setCountFindedWords( int countFindedWords )
{
    m_countFindedWords = countFindedWords;
}
