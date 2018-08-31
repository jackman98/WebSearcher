#ifndef SEARCHER_H
#define SEARCHER_H

#include <QObject>
#include <QRunnable>
#include "page.h"
#include "pagedownloader.h"
#include "pageparser.h"

class SearchWorker : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit SearchWorker( Page* page, QObject* parent = nullptr );
    ~SearchWorker( );

    Page* page( ) const;

protected:
    void run( ) override;

signals:
    void finished( );

    // public slots:
    //    void finish( );

private:
    Page* mPage;
};

#endif  // SEARCHER_H
