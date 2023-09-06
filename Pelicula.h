//
// Created by Alan Corona on 6/12/2023.
//


#ifndef CORONASTREAMING_PELICULA_H
#define CORONASTREAMING_PELICULA_H

#include <string>
#include "Video.h"
/*
Archivo: Pelicula.cpp
Autor: Alan Corona
Fecha de creación: 12/06/2023

Descripción:
Este archivo contiene la implementación de la clase Pelicula, que representa una película en el catálogo de videos.
Define los métodos de la clase, incluyendo el constructor predeterminado, el constructor con parámetros,
los métodos de acceso y modificación de la duración, y el método para imprimir los detalles de la película.
*/

class Pelicula : public Video
{
public:
    Pelicula();
    Pelicula(const std::string&, int, const std::string&, const std::string&, int, float, int);

    int getDuracion() const;
    void setDuracion(int);
    void imprime() override;

private:
    int duracion;
};

#endif //CORONASTREAMING_PELICULA_H
