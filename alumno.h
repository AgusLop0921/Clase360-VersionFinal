#ifndef ALUMNO_H
#define ALUMNO_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

namespace Ui {
class Alumno;
}

class Alumno : public QWidget
{
    Q_OBJECT

public:
    explicit Alumno(QWidget *parent = 0);
    ~Alumno();

    QNetworkAccessManager *manager;

    void setUrlImagenUsuario(QString URL);

    bool getIsOnline() const;
    void setIsOnline(bool value);

    QTimer *timer;
    QPen pen;
    QPainter painter;
    QPainterPath path;

signals:
    void enviarMensaje(QString alumno);

private:
    Ui::Alumno *ui;

    QString alumno, mensaje,imgUsuario;
    QImage image;

    bool isOnline;

    QUrl url;

protected:
    void paintEvent(QPaintEvent * e);

private slots:
    void slot_imagenDescargada(QNetworkReply *reply);
    void descargarImagen();


};

#endif // ALUMNO_H
