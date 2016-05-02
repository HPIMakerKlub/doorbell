#include "doorbell.h"

Doorbell::Doorbell(const QUrl &url, QObject *parent)
    : QObject(parent),
      m_url(url)
{
    connect(&m_webSocket, &QWebSocket::connected, this, &Doorbell::onConnected);
    m_webSocket.open(QUrl(url));

    player.setMedia(QUrl::fromLocalFile("C:/Zeugs/bell.wav"));
    player.setVolume(100);
}

void Doorbell::onConnected()
{
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &Doorbell::onTextMessageReceived);
    m_webSocket.sendTextMessage(QStringLiteral("Hallo, hier ist die Tuerklingel."));
}

void Doorbell::onTextMessageReceived(QString message)
{
    if(message == "bell")
    {
        player.setPosition(0);
    }
    player.play();
}
