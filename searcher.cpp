#include "searcher.h"

Searcher::Searcher(DataProvider *dataProvider, QObject *parent) : QObject(parent), m_dataProvider(dataProvider)
{

}

void Searcher::start()
{
    Page page;
    page.setUrl(startURl());


    pageDownloader.downloadPage(&page);
}
