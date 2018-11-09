#ifndef MENSAJE_H
#define MENSAJE_H

#include <QObject>

#include <QNetworkAccessManager>
#include <QNetworkReply>
class Mensaje : public QObject
{
    Q_OBJECT
public:
    explicit Mensaje(QObject *parent = nullptr);

    QNetworkAccessManager *manager;

    int intervaloMensajes;

    QString ultimoMensaje, urlMensaje;

private slots:
    void slot_mensajeDescargado(QNetworkReply *reply);

    void descargarMensaje();

signals:
    void signal_escribirMensaje(QString);

};

#endif // MENSAJE_H
