#include "mensaje.h"
#include <QTimer>
#include <QNetworkRequest>

Mensaje::Mensaje(QObject *parent) : QObject(parent),
                                    intervaloMensajes(3000)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(descargarMensaje()));
    timer->start(intervaloMensajes);

    manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slot_mensajeDescargado(QNetworkReply*)));

}

void Mensaje::descargarMensaje()
{
    urlMensaje = "http://doc.qt.io/archives/qt-5.7/qnetworkaccessmanager.html";
    QUrl url(urlMensaje);
    QNetworkRequest request(url);
    manager->get(request);

}

void Mensaje::slot_mensajeDescargado(QNetworkReply *reply)
{
    QByteArray ba = reply->readAll();
    qWarning() <<"ba" <<ba.size();
    emit signal_escribirMensaje("mensaje");

}
