#ifndef GRILLA_H
#define GRILLA_H

#include "alumno.h"

#include <QWidget>
#include <QVector>
#include <QGridLayout>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
class Grilla : public QWidget
{
    Q_OBJECT
public:
    explicit Grilla(QWidget *parent = nullptr);

    void configurar( QString url );
    void configurarCeldas();

    QNetworkAccessManager *manager;


private:
    QVector< Alumno* > vAlumnos;
    QGridLayout * layout;

signals:

public slots:
private slots:
    void descargaFinalizada(QNetworkReply *reply);
};

#endif // GRILLA_H
