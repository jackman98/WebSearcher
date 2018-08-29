#include "page.h"

Page::Page(QObject *parent) : QObject(parent)
{

}

QUrl Page::url() const
{
    return m_url;
}

int Page::countOfFindedUrl() const
{
    return m_countOfFindedUrl;
}

int Page::countOfSearchText() const
{
    return m_countOfSearchText;
}

bool Page::isDownloaded() const
{
    return m_isDownloaded;
}

void Page::setUrl(QUrl url)
{
    if (m_url == url)
        return;

    m_url = url;
    emit urlChanged(m_url);
}

void Page::setCountOfFindedUrl(int countOfFindedUrl)
{
    if (m_countOfFindedUrl == countOfFindedUrl)
        return;

    m_countOfFindedUrl = countOfFindedUrl;
    emit countOfFindedUrlChanged(m_countOfFindedUrl);
}

void Page::setCountOfSearchText(int countOfSearchText)
{
    if (m_countOfSearchText == countOfSearchText)
        return;

    m_countOfSearchText = countOfSearchText;
    emit countOfSearchTextChanged(m_countOfSearchText);
}

void Page::setIsDownloaded(bool isDownloaded)
{
    if (m_isDownloaded == isDownloaded)
        return;

    m_isDownloaded = isDownloaded;
    emit isDownloadedChanged(m_isDownloaded);
}

void Page::setHtmlText(const QString &text)
{
    m_htmlText = text;
}
