#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "worker.h"
#include <QThread>
#include <QMainWindow>
#include <QApplication>
#include <QCloseEvent>

class Controller : public QMainWindow
{
    Q_OBJECT
public:
    explicit Controller(QMainWindow *parent = nullptr)
        : QMainWindow(parent), m_worker(new Worker)
    {
        setFixedSize(640, 400);
        QThread *thread = new QThread;
        m_worker->moveToThread(thread);
        connect(thread, &QThread::started, m_worker, &Worker::operate);
        connect(m_worker, &Worker::resultReady, this, &Controller::handleResults);
        connect(m_worker, &Worker::finished, thread, &QThread::quit);
        connect(thread, &QThread::finished, thread, &QObject::deleteLater);
        connect(m_worker, &Worker::finished, m_worker, &QObject::deleteLater);
        connect(m_worker, &Worker::finished, qApp, &QApplication::quit);
        thread->start();
    }

    ~Controller() {}

public slots:
    void handleResults(const QString &result){
        qDebug() << result;
    }

protected:
    void closeEvent(QCloseEvent *event) override
    {
        m_worker->finish();
        event->ignore();
    }

private:
    Worker *m_worker;
};

#endif // CONTROLLER_H
