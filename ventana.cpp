#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    grilla = new Grilla(this);
    grilla->configurar( "https://www.google.com.ar/" );

    mensaje = new Mensaje;

    connect(mensaje,SIGNAL(signal_escribirMensaje(QString)),this,SLOT(slot_recibirMensaje(QString)));
}

Ventana::~Ventana()
{
    delete ui;
}
void Ventana::slot_recibirMensaje(QString mensaje){

    qWarning()<<"MENSAJE RECIBIDO";
    ui->textEdit->setText(mensaje);
}
