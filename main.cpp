#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "dataprovider.h"
#include "searcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    DataProvider *provider = new DataProvider();
    Searcher searcher;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    engine.rootContext()->setContextProperty("dataProvider", provider);
    engine.rootContext()->setContextProperty("searcher", &searcher);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
