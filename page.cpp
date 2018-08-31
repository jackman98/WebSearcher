#include "page.h"
#include <QDebug>

Page::Page( QObject* parent )
    : QObject( parent )
{
}

Page::Page( QUrl url, QString searchText, QObject* parent )
    : QObject( parent )
    , m_url( url )
    , mSearchText( searchText )
{
}

Page::~Page( )
{
    qDebug( ) << __PRETTY_FUNCTION__;
}

QUrl
Page::url( ) const
{
    return m_url;
}

int
Page::countOfFindedUrl( ) const
{
    return m_countOfFindedUrl;
}

int
Page::countOfSearchText( ) const
{
    return m_countOfSearchText;
}

bool
Page::isDownloaded( ) const
{
    return m_isDownloaded;
}

void
Page::setUrl( QUrl url )
{
    if ( m_url == url )
        return;

    m_url = url;
    emit urlChanged( m_url );
}

void
Page::setCountOfFindedUrl( int countOfFindedUrl )
{
    if ( m_countOfFindedUrl == countOfFindedUrl )
        return;

    m_countOfFindedUrl = countOfFindedUrl;
    emit countOfFindedUrlChanged( m_countOfFindedUrl );
}

void
Page::setCountOfSearchText( int countOfSearchText )
{
    if ( m_countOfSearchText == countOfSearchText )
        return;

    m_countOfSearchText = countOfSearchText;
    emit countOfSearchTextChanged( m_countOfSearchText );
}

void
Page::setIsDownloaded( bool isDownloaded )
{
    if ( m_isDownloaded == isDownloaded )
        return;

    m_isDownloaded = isDownloaded;
    emit isDownloadedChanged( m_isDownloaded );
}

QString
Page::searchText( ) const
{
    return mSearchText;
}

bool
Page::isExecuted( ) const
{
    return m_isExecuted;
}

void
Page::setSearchText( const QString& searchText )
{
    mSearchText = searchText;
}

void
Page::setIsExecuted( bool isExecuted )
{
    if ( m_isExecuted == isExecuted )
        return;

    m_isExecuted = isExecuted;
    emit isExecutedChanged( m_isExecuted );
}

QString
Page::htmlText( ) const
{
    return m_htmlText;
}

void
Page::setHtmlText( const QString& text )
{
    m_htmlText = text;
}
