#include <QDebug>
#include <QScriptEngine>
#include <QCoreApplication>

//Logger class, for console.log
class Logger: public QObject
{
    Q_OBJECT
public:
    Logger( QObject*parent = nullptr): QObject(parent) {}

public slots:
    void log(const QString& str){ qDebug() << str; }
};

#include "main.moc"

int main(int argn, char* args[])
{
    QCoreApplication app(argn, args);
    QScriptEngine engine;
    // Logger
    Logger logger;
    QScriptValue loggerResult = engine.newQObject(&logger);
    engine.globalObject().setProperty("console", loggerResult);

    // TODO CONFIG HERE FOR WINDOW OBJECT
    //engine.globalObject().setProperty(QString("window"),
    //    engine.newObject()); //Does not work, obviously

    engine.evaluate("window=this; var test=42; console.log(test); console.log(window.test)");
    if (engine.hasUncaughtException())
    {
        int line = engine.uncaughtExceptionLineNumber();
        QScriptValue error = engine.uncaughtException();
        QStringList errorStr = engine.uncaughtExceptionBacktrace();
        qDebug() << "Exception at:" << line << ":" << error.toString();
    }
}
