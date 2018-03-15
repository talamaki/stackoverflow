#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QDateTime>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QVariantMap parameters;
    parameters[QStringLiteral("esri.useragent")] = QStringLiteral("Générateur Simplifié de Plans de Vol");

    QObject *item = engine.rootObjects().first();
    Q_ASSERT(item);

    QMetaObject::invokeMethod(item, "initializeProviders",
                              Q_ARG(QVariant, QVariant::fromValue(parameters)));

    // Generate error: file open fails
    FILE *pFile = fopen (NULL,"w");
    // fputs with invalid file displays in debug mode "Invalid parameter passed to C runtime function."
    fputs("abc",pFile);
    // fprintf with invalid file crashes the program
    fprintf(pFile, "def\n");

    return app.exec();
}
