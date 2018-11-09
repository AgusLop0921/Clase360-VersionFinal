#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

#include "grilla.h"
#include "mensaje.h"

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();

    Grilla *grilla;
    Mensaje *mensaje;
private:
    Ui::Ventana *ui;

private slots:
   void slot_recibirMensaje(QString mensaje);
};

#endif // VENTANA_H
