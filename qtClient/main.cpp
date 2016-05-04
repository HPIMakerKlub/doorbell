//"http://doc.qt.io/qt-5/qtwebsockets-echoclient-example.html"
#include <QCoreApplication>
#include "doorbell.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QUrl url = QUrl(QStringLiteral("ws://j.braun.mooo.com:8081"));
    Doorbell bell(url);

    return a.exec();
}
