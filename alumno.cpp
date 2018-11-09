#include "alumno.h"
#include "ui_alumno.h"
#include <QTimer>
#include <QPainter>
#include <QImage>
#include <QDebug>
#include <QMovie>
#include <QUrl>

Alumno::Alumno(QWidget *parent) :QWidget(parent),
                                 alumno("Empty"),
                                 isOnline(false),
                                 url(""),
                                 ui(new Ui::Alumno)
{
    ui->setupUi(this);

    image.load(":/Recursos/usuario.jpg");
    ui->label->setText(alumno);
    ui->label->move((this->width()/2)-20,150);

    manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slot_imagenDescargada(QNetworkReply*)));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(descargarImagen()));
    timer->start(1000);

}
Alumno::~Alumno()
{
    delete ui;
}

bool Alumno::getIsOnline() const
{
    return isOnline;
}

void Alumno::setIsOnline(bool value)
{
    isOnline = value;
}

void Alumno::setUrlImagenUsuario(QString URL)
{
    url = URL;

}
/**
 * @brief Alumno::descargarImagen Permite descargar la imagen del usuario.
 *
 */
void Alumno::descargarImagen()
{
    QNetworkRequest request(url);
    manager->get(request);
}
void Alumno::paintEvent(QPaintEvent * e)
{
   QPainter painter(this);

//   path;
//   path.addRoundedRect(QRectF(10, 0, this->width()-30, this->height()-30), 10, 10);

//   pen.setColor(Qt::black);
//   pen.setWidth(4);
//   painter.setPen(pen);


//   painter.fillPath(path, Qt::green);

//   painter.drawPath(path);

   painter.drawImage(20, 10, image.scaled(this->width()-50, this->height()-50));
}

void Alumno::slot_imagenDescargada(QNetworkReply *reply)
{
    QByteArray ba = reply->readAll();
    image = QImage::fromData(ba);
    this->repaint();
}


