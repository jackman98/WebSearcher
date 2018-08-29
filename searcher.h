#ifndef SEARCHER_H
#define SEARCHER_H

#include <QObject>
#include "page.h"
#include "pagedownloader.h"
#include "dataprovider.h"

class Searcher : public QObject
{
    Q_OBJECT


public:
    explicit Searcher(DataProvider *dataProvider, QObject *parent = nullptr);

signals:

public slots:
    void start();

private:
    PageDownloader m_pageDownloader;
    Page m_startPage;
    DataProvider *m_dataProvider;
};

#endif // SEARCHER_H
