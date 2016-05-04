#ifndef DOORBELL_H
#define DOORBELL_H

#include <QObject>
#include <QtWebSockets/QtWebSockets>
#include <QMediaPlayer>

class Doorbell : public QObject
{
    Q_OBJECT
private:
    QWebSocket m_webSocket;
    QUrl m_url;
    QMediaPlayer player;

public:
    explicit Doorbell(const QUrl &url, QObject *parent = 0);

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);
};

#endif // DOORBELL_H
