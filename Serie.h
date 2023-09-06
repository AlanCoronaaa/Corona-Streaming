//
// Created by Alan Corona on 6/12/2023.
//

#ifndef CORONASTREAMING_SERIE_H
#define CORONASTREAMING_SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <map>
/*La clase Serie se deriva de la clase base Video utilizando el especificador de acceso public. Agrega atributos y métodos específicos relacionados con una serie.Esta clase hereda los miembros públicos de la clase Video, incluyendo sus atributos y métodos.
 * Además, declara miembros adicionales específicos de una serie de televisión, como episodios (un mapa que representa los episodios).
 * La clase proporciona métodos para acceder y modificar los episodios, calcular la duración promedio y sobrescribir el método imprime para imprimir los detalles de la serie de televisión.*/
class Serie : public Video
{
public:
    Serie();
    Serie(std::string, int, std::string, std::string, int, float, std::map<std::pair<int, int>, Episodio>);
    std::map<std::pair<int, int>, Episodio> getEpisodios() const;
    void setEpisodios(std::map<std::pair<int, int>, Episodio>);
    int duracionPromedio() const;
    void imprime() override;

private:
    std::map<std::pair<int, int>, Episodio> episodios;
};


#endif //CORONASTREAMING_SERIE_H
/*
Archivo: Serie.cpp
Autor: Alan Corona
Fecha de creación: 12/06/2023

Descripción:
Este archivo contiene la implementación de la clase Serie, que representa una serie de video en el catálogo.
Define los métodos de la clase, incluyendo el constructor predeterminado, el constructor con parámetros,
los métodos de acceso y modificación de los atributos, así como la función para calcular la duración promedio
de los episodios y el método para imprimir los detalles de la serie.


#include "Serie.h"
#include <iostream>

// Constructor predeterminado
Serie::Serie()
{
}

// Constructor con parámetros
Serie::Serie(std::string tipoDeVideo, int id, std::string titulo, std::string genero, int numeroDeCalificaciones, float calificacion, std::map<std::pair<int, int>, Episodio> episodios) : Video(tipoDeVideo, id, titulo, genero, numeroDeCalificaciones, calificacion)
{
    this->setEpisodios(episodios);
}

// Método de acceso para obtener los episodios de la serie
std::map<std::pair<int, int>, Episodio> Serie::getEpisodios() const
{
    return this->episodios;
}

// Método de modificación para establecer los episodios de la serie
void Serie::setEpisodios(std::map<std::pair<int, int>, Episodio> episodios)
{
    this->episodios = episodios;
}

// Método para calcular la duración promedio de los episodios de la serie
int Serie::duracionPromedio() const
{
    int numeroDeEpisodios = 0;
    int sumaDeDuraciones = 0;
    for (auto i : this->episodios)
    {
        Episodio episodio = i.second;
        ++numeroDeEpisodios;
        sumaDeDuraciones += episodio.getDuracion();
    }
    return sumaDeDuraciones / numeroDeEpisodios;
}

// Método para imprimir los detalles de la serie
void Serie::imprime()
{
    std::cout << "---- " << this->getTitulo() << " (" << this->getId() << ") ----" << std::endl;
    std::cout << "Género: " << this->getGenero() << std::endl;
    std::cout << "Calificación: " << this->getCalificacion() << std::endl;
    std::cout << "Duración promedio: " << this->duracionPromedio() << std::endl;
    std::cout << "-- Episodios --" << std::endl;
    for (auto i : this->episodios)
    {
        Episodio episodio = i.second;
        episodio.imprime();
    }
    std::cout << "--" << std::endl;
    std::cout << "----" << std::endl;
}
*/