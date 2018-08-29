#ifndef PAGE_H
#define PAGE_H
#include <QObject>
#include <QQueue>
#include <QUrl>

class Page : public QObject
{
    Q_OBJECT

    //    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY( int countOfFindedUrl READ countOfFindedUrl NOTIFY countOfFindedUrlChanged )
    Q_PROPERTY( int countOfSearchText READ countOfSearchText NOTIFY countOfSearchTextChanged )
    Q_PROPERTY(
            bool isDownloaded READ isDownloaded WRITE setIsDownloaded NOTIFY isDownloadedChanged )

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
    QQueue< Page* > subpages;

public slots:
    void setUrl( QUrl url );
    void setCountOfFindedUrl( int countOfFindedUrl );
    void setCountOfSearchText( int countOfSearchText );
    void setIsDownloaded( bool isDownloaded );
    void setSearchText( const QString& searchText );

signals:
    void urlChanged( QUrl url );
    void countOfFindedUrlChanged( int countOfFindedUrl );
    void countOfSearchTextChanged( int countOfSearchText );
    void isDownloadedChanged( bool isDownloaded );

private:
    QUrl m_url;
    int m_countOfSearchText = 0;
    int m_countOfFindedUrl = 0;
    bool m_isDownloaded = false;
    QString m_htmlText = "";
    QString mSearchText = "";
};

#endif  // PAGE_H
