#include "pageparser.h"
#include <QDebug>
#include <QQueue>
#include <QRegularExpression>

PageParser::PageParser( QObject* parent )
    : QObject( parent )
{
}

void
PageParser::startParse( Page* page )
{
    m_page = page;

    QString text = m_page->htmlText( );

    QRegularExpression regExpForText( m_page->searchText( ) );

    auto itForText = regExpForText.globalMatch( text );
    int countFindedText = 0;
    while ( itForText.hasNext( ) )
    {
        ++countFindedText;
        qDebug( ) << itForText.next( ).captured( 0 );
    }

    m_page->setCountOfSearchText( countFindedText );

    QRegularExpression regExpForUrl(
            "(\\/\\S*)?(((https|http|ftp)://)((\\w|-)+)(([.]|[/])((\\w|-)+))+)(\\/\\S*)?" );

    auto itForUrl = regExpForUrl.globalMatch( text );
    int countFindedUrl = 0;

    while ( itForUrl.hasNext( ) )
    {
        ++countFindedUrl;
        m_page->subpages.append(
                new Page( itForUrl.next( ).captured( 0 ), m_page->searchText( ) ) );
    }

    emit finished( );
}
