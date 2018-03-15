#ifndef WORKER_H
#define WORKER_H

#include <QDebug>
#include <QStringList>
#include <QInputDialog>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT

public:
    explicit Worker(QObject *parent = nullptr)
        : QObject(parent), m_continue(false) {}
    virtual ~Worker() {}

public slots:
    void operate(){
        m_continue = true;
        static QString result;
        while(m_continue)
        {
            result.append('a');
            QThread::sleep(2);
            emit resultReady(result);
        }
        emit finished();
    }

    void finish() {
        m_continue = false;
    }

signals:
    void finished();
    void resultReady(const QString &result);

private:
    bool m_continue;
};

#endif // WORKER_H
