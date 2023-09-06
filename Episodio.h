//
// Created by Alan Corona on 6/12/2023.
//

#ifndef CORONASTREAMING_EPISODIO_H
#define CORONASTREAMING_EPISODIO_H

/*
Archivo: Episodio.cpp
Autor: Alan Corona
Fecha de creación: 11/06/2023

Descripción:
Este archivo contiene la implementación de la clase Episodio, que representa un episodio de una serie en el catálogo de videos.
Define los métodos de la clase, incluyendo el constructor predeterminado, el constructor con parámetros,
los métodos de acceso y modificación de los atributos, el método para imprimir los detalles del episodio,
y la sobrecarga del operador de extracción (>>) para leer los datos de un episodio desde un flujo de entrada.


#include "Episodio.h"
#include <iostream>

// Constructor predeterminado
Episodio::Episodio()
{
    this->setTemporada(0);
    this->setEpisodio(0);
    this->setTitulo("");
    this->setDuracion(0);
}

// Constructor con parámetros
Episodio::Episodio(int temporada, int episodio, std::string titulo, int duracion)
{
    this->setTemporada(temporada);
    this->setEpisodio(episodio);
    this->setTitulo(titulo);
    this->setDuracion(duracion);
}

// Método de acceso para obtener el número de temporada
int Episodio::getTemporada() const
{
    return this->temporada;
}

// Método de acceso para obtener el número de episodio
int Episodio::getEpisodio() const
{
    return this->episodio;
}

// Método de acceso para obtener el título del episodio
std::string Episodio::getTitulo() const
{
    return this->titulo;
}

// Método de acceso para obtener la duración del episodio
int Episodio::getDuracion() const
{
    return this->duracion;
}

// Método de modificación para establecer el número de temporada
void Episodio::setTemporada(int temporada)
{
    this->temporada = temporada;
}

// Método de modificación para establecer el número de episodio
void Episodio::setEpisodio(int episodio)
{
    this->episodio = episodio;
}

// Método de modificación para establecer el título del episodio
void Episodio::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

// Método de modificación para establecer la duración del episodio
void Episodio::setDuracion(int duracion)
{
    this->duracion = duracion;
}

// Método para imprimir los detalles del episodio
void Episodio::imprime()
{
    std::cout << "T." << this->temporada << " ";
    std::cout << "E." << this->episodio << " ";
    std::cout << this->titulo << " ";
    std::cout << "(" << this->duracion << " min)" << std::endl;
}

// Sobrecarga del operador de extracción (>>) para leer los datos de un episodio desde un flujo de entrada
std::istream &operator>>(std::istream &entrada, Episodio &episodio)
{
    entrada >> episodio.temporada >> episodio.episodio >> episodio.titulo >> episodio.duracion;
    episodio.setTemporada(episodio.temporada);
    episodio.setEpisodio(episodio.episodio);
    episodio.setTitulo(episodio.titulo);
    episodio.setDuracion(episodio.duracion);
    return entrada;
}
*/
#include <string>
class Episodio
{
public:
    Episodio();
    Episodio(int, int, std::string, int);
    int getTemporada() const;
    int getEpisodio() const;
    std::string getTitulo() const;
    int getDuracion() const;
    void setTemporada(int);
    void setEpisodio(int);
    void setTitulo(std::string);
    void setDuracion(int);
    void imprime();
    friend std::istream &operator>>(std::istream &, Episodio &);
private:
    int temporada;
    int episodio;
    std::string titulo;
    int duracion;
};

#endif //CORONASTREAMING_EPISODIO_H
