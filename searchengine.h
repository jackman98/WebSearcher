#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <QObject>
#include <QQueue>
#include "QThreadPool"
#include "dataprovider.h"
#include "page.h"

class SearchEngine : public QObject
{
    Q_OBJECT

public:
    explicit SearchEngine( DataProvider* mDataProvider, QObject* parent = nullptr );

signals:
    void pagesChanged( );

public slots:
    void start( );
    void procces( );
    void addPages( );

private:
    Page mStartPage;
    DataProvider* mDataProvider;
    QThreadPool mThreadPool;
    QQueue< Page* > mPages;
};
#endif  // SEARCHENGINE_H
