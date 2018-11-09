#include "ventana.h"
#include "grilla.h"

#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Grilla grilla;
//    grilla.configurar( "https://www.google.com.ar/" );
//    grilla.showFullScreen();


    Ventana v;
    v.setWindowTitle("Ventana");
    v.show();
    return a.exec();
}
