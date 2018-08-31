#ifndef PAGE_H
#define PAGE_H
#include <QList>
#include <QObject>
#include <QUrl>

class Page : public QObject
{
    Q_OBJECT

    //    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY( int countOfFindedUrl READ countOfFindedUrl NOTIFY countOfFindedUrlChanged )
    Q_PROPERTY( int countOfSearchText READ countOfSearchText NOTIFY countOfSearchTextChanged )
    Q_PROPERTY(
            bool isDownloaded READ isDownloaded WRITE setIsDownloaded NOTIFY isDownloadedChanged )
    Q_PROPERTY( bool isExecuted READ isExecuted WRITE setIsExecuted NOTIFY isExecutedChanged )

public:
    explicit Page( QObject* parent = nullptr );
    Page( QUrl url, QString searchText, QObject* parent = nullptr );
    ~Page( );

    QUrl url( ) const;
    int countOfFindedUrl( ) const;
    int countOfSearchText( ) const;
    bool isDownloaded( ) const;

    void setHtmlText( const QString& text );

    QString htmlText( ) const;

    QString searchText( ) const;
    QList< Page* > subpages;

    bool isExecuted( ) const;

public slots:
    void setUrl( QUrl url );
    void setCountOfFindedUrl( int countOfFindedUrl );
    void setCountOfSearchText( int countOfSearchText );
    void setIsDownloaded( bool isDownloaded );
    void setSearchText( const QString& searchText );

    void setIsExecuted( bool isExecuted );

signals:
    void urlChanged( QUrl url );
    void countOfFindedUrlChanged( int countOfFindedUrl );
    void countOfSearchTextChanged( int countOfSearchText );
    void isDownloadedChanged( bool isDownloaded );

    void isExecutedChanged( bool isExecuted );

private:
    QUrl m_url;
    int m_countOfSearchText = 0;
    int m_countOfFindedUrl = 0;
    bool m_isDownloaded = false;
    QString m_htmlText = "";
    QString mSearchText = "";
    bool m_isExecuted = false;
};

#endif  // PAGE_H
