#include "grilla.h"

Grilla::Grilla(QWidget *parent) : QWidget(parent), layout( new QGridLayout( this ) )
{
    manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(descargaFinalizada(QNetworkReply*)));
}

/**
 * @brief Grilla::configurar
 * @param url Permite obtener un JSON desde la API con la lista de los alumnos conectados con toda su info, por ejemplo, idAlumno,
 * urlCamara, urlFotoPerfil, Nombre Completo, etc
 * Este metodo usara esta info para conocer cuantas celdas debera tener esta grilla. Es decir, configura tambien el layout con la
 * cantidad de filas y columnas segun los alumnos conectados.
 *
 */
void Grilla::configurar(QString url)
{
    //
    QNetworkRequest request(url);
    manager->get(request);
}

/**
 * @brief Grilla::configurarCeldas Este metodo lee el vector de todos los alumnos leidos del json y configura el QGridLayout.
 *
 * Esta Grilla solo acepta entre 1 y 12 alumnos
 */
void Grilla::configurarCeldas()
{
    int cantidadDeAlumnos = vAlumnos.size();

    if ( cantidadDeAlumnos == 0 || cantidadDeAlumnos > 12)
        return;

    switch ( cantidadDeAlumnos )  {
    case 1:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        break;

    case 2:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        break;

    case 3:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 0, 2 );
        break;

    case 4:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 1, 0 );
        layout->addWidget( vAlumnos.at( 3 ), 1, 1 );
        break;

    case 5:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 0, 2 );
        layout->addWidget( vAlumnos.at( 3 ), 1, 0 );
        layout->addWidget( vAlumnos.at( 4 ), 1, 1 );
        break;

    case 6:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 0, 2 );
        layout->addWidget( vAlumnos.at( 3 ), 1, 0 );
        layout->addWidget( vAlumnos.at( 4 ), 1, 1 );
        layout->addWidget( vAlumnos.at( 5 ), 1, 2 );
        break;
    case 7:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 0, 2 );
        layout->addWidget( vAlumnos.at( 3 ), 1, 0 );
        layout->addWidget( vAlumnos.at( 4 ), 1, 1 );
        layout->addWidget( vAlumnos.at( 5 ), 1, 2 );
        layout->addWidget( vAlumnos.at( 6 ), 2, 0 );
        break;

    case 8:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 0, 2 );
        layout->addWidget( vAlumnos.at( 3 ), 1, 0 );
        layout->addWidget( vAlumnos.at( 4 ), 1, 1 );
        layout->addWidget( vAlumnos.at( 5 ), 1, 2 );
        layout->addWidget( vAlumnos.at( 6 ), 2, 0 );
        layout->addWidget( vAlumnos.at( 7 ), 2, 1 );
        break;

    case 9:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 0, 2 );
        layout->addWidget( vAlumnos.at( 3 ), 1, 0 );
        layout->addWidget( vAlumnos.at( 4 ), 1, 1 );
        layout->addWidget( vAlumnos.at( 5 ), 1, 2 );
        layout->addWidget( vAlumnos.at( 6 ), 2, 0 );
        layout->addWidget( vAlumnos.at( 7 ), 2, 1 );
        layout->addWidget( vAlumnos.at( 8 ), 2, 2 );
        break;

    case 10:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 0, 2 );
        layout->addWidget( vAlumnos.at( 3 ), 1, 0 );
        layout->addWidget( vAlumnos.at( 4 ), 1, 1 );
        layout->addWidget( vAlumnos.at( 5 ), 1, 2 );
        layout->addWidget( vAlumnos.at( 6 ), 2, 0 );
        layout->addWidget( vAlumnos.at( 7 ), 2, 1 );
        layout->addWidget( vAlumnos.at( 8 ), 2, 2 );
        layout->addWidget( vAlumnos.at( 9 ), 3, 0 );
        break;

    case 11:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 0, 2 );
        layout->addWidget( vAlumnos.at( 3 ), 1, 0 );
        layout->addWidget( vAlumnos.at( 4 ), 1, 1 );
        layout->addWidget( vAlumnos.at( 5 ), 1, 2 );
        layout->addWidget( vAlumnos.at( 6 ), 2, 0 );
        layout->addWidget( vAlumnos.at( 7 ), 2, 1 );
        layout->addWidget( vAlumnos.at( 8 ), 2, 2 );
        layout->addWidget( vAlumnos.at( 9 ), 3, 0 );
        layout->addWidget( vAlumnos.at( 10 ), 3, 1);
        break;

    case 12:
        layout->addWidget( vAlumnos.at( 0 ), 0, 0 );
        layout->addWidget( vAlumnos.at( 1 ), 0, 1 );
        layout->addWidget( vAlumnos.at( 2 ), 0, 2 );
        layout->addWidget( vAlumnos.at( 3 ), 1, 0 );
        layout->addWidget( vAlumnos.at( 4 ), 1, 1 );
        layout->addWidget( vAlumnos.at( 5 ), 1, 2 );
        layout->addWidget( vAlumnos.at( 6 ), 2, 0 );
        layout->addWidget( vAlumnos.at( 7 ), 2, 1 );
        layout->addWidget( vAlumnos.at( 8 ), 2, 2 );
        layout->addWidget( vAlumnos.at( 9 ), 3, 0 );
        layout->addWidget( vAlumnos.at( 10 ), 3, 1);
        layout->addWidget( vAlumnos.at( 11 ), 3, 2);


    default:;

    }

    this->setLayout( layout );
}

void Grilla::descargaFinalizada( QNetworkReply * reply )  {


    // Aca se leen los datos y se obtiene por ejemplo: 6 alumnos

    // Se crean los 6 alumnos

    int alumnosObtenidos = 12;

    for ( int i = 0 ; i < alumnosObtenidos ; i++ )  {
        Alumno * alumno = new Alumno( this );
        alumno->setUrlImagenUsuario("https://3.bp.blogspot.com/-oj3d5-sYa10/VQYQbVZMJsI/AAAAAAAAh6o/J_jPQNRELtw/s1600/Jennifer+Aniston.jpg");

        vAlumnos.push_back( alumno );
    }

    this->configurarCeldas();


}
