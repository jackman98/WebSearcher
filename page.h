#ifndef PAGE_H
#define PAGE_H
#include <QObject>
#include <QUrl>

class Page : public QObject
{
    Q_OBJECT

//    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(int countOfFindedUrl READ countOfFindedUrl NOTIFY countOfFindedUrlChanged)
    Q_PROPERTY(int countOfSearchText READ countOfSearchText NOTIFY countOfSearchTextChanged)
    Q_PROPERTY(bool isDownloaded READ isDownloaded WRITE setIsDownloaded NOTIFY isDownloadedChanged)

public:
    explicit Page(QObject *parentPage = nullptr);

    QUrl url() const;
    int countOfFindedUrl() const;
    int countOfSearchText() const;
    bool isDownloaded() const;

public slots:
    void setUrl(QUrl url);
    void setCountOfFindedUrl(int countOfFindedUrl);
    void setCountOfSearchText(int countOfSearchText);
    void setIsDownloaded(bool isDownloaded);

signals:
    void urlChanged(QUrl url);
    void countOfFindedUrlChanged(int countOfFindedUrl);
    void countOfSearchTextChanged(int countOfSearchText);
    void isDownloadedChanged(bool isDownloaded);

private:
    QUrl m_url;
    int m_countOfSearchText = -1;
    int m_countOfFindedUrl = -1;
    bool m_isDownloaded = false;
    QString htmlText = "";
};

#endif // PAGE_H
