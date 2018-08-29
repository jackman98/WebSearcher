#ifndef PAGEPARSER_H
#define PAGEPARSER_H

#include <QObject>
#include "page.h"

class PageParser : public QObject
{
    Q_OBJECT
public:
    explicit PageParser( QObject* parent = nullptr );

signals:
    void started( );
    void finished( );

public slots:
    void startParse( Page* page );

private:
    Page* m_page;
};

#endif  // PAGEPARSER_H
