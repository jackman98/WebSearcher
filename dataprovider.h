#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>
#include <QUrl>
#include "pagedownloader.h"

class DataProvider : public QObject
{
    Q_OBJECT

    Q_PROPERTY( QUrl startURl READ startURl WRITE setStartURl NOTIFY startURlChanged )
    Q_PROPERTY( int countOfThreads READ countOfThreads WRITE setCountOfThreads NOTIFY
                        countOfThreadsChanged )
    Q_PROPERTY( QString searchText READ searchText WRITE setSearchText NOTIFY searchTextChanged )
    Q_PROPERTY( int maxCountScanningURL READ maxCountScanningURL WRITE setMaxCountScanningURL NOTIFY
                        maxCountScanningURLChanged )
    Q_PROPERTY( int countFindedWords READ countFindedWords NOTIFY countFindedWordsChanged )

public:
    explicit DataProvider( QObject* parent = nullptr );

    QUrl startURl( ) const;
    int countOfThreads( ) const;
    QString searchText( ) const;
    int maxCountScanningURL( ) const;

    int countFindedWords( ) const;

    void setCountFindedWords( int countFindedWords );

signals:
    void startURlChanged( QUrl startURl );
    void countOfThreadsChanged( int countOfThreads );
    void searchTextChanged( QString searchText );
    void maxCountScanningURLChanged( int maxCountScanningURL );

    void countFindedWordsChanged( int countFindedWords );

public slots:
    void setStartURl( QUrl startURl );
    void setCountOfThreads( int countOfThreads );
    void setSearchText( QString searchText );
    void setMaxCountScanningURL( int maxCountScanningURL );

private:
    QUrl m_startURl;
    int m_countOfThreads;
    QString m_searchText;
    int m_maxCountScanningURL;
    PageDownloader pageDownloader;
    int m_countFindedWords = 0;
};

#endif  // DATAPROVIDER_H
