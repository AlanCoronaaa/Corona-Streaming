/*
//
// Created by Alan Corona on 6/12/2023.
//
*/

#include "Episodio.h"
#include <iostream>

Episodio::Episodio()
{
    this->setTemporada(0);
    this->setEpisodio(0);
    this->setTitulo("");
    this->setDuracion(0);
}

Episodio::Episodio(int temporada, int episodio, std::string titulo, int duracion)
{
    this->setTemporada(temporada);
    this->setEpisodio(episodio);
    this->setTitulo(titulo);
    this->setDuracion(duracion);
}

int Episodio::getTemporada() const
{
    return this->temporada;
}

int Episodio::getEpisodio() const
{
    return this->episodio;
}

std::string Episodio::getTitulo() const
{
    return this->titulo;
}

int Episodio::getDuracion() const
{
    return this->duracion;
}

void Episodio::setTemporada(int temporada)
{
    this->temporada = temporada;
}

void Episodio::setEpisodio(int episodio)
{
    this->episodio = episodio;
}

void Episodio::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

void Episodio::setDuracion(int duracion)
{
    this->duracion = duracion;
}

void Episodio::imprime()
{
    std::cout << "T." << this->temporada << " ";
    std::cout << "E." << this->episodio << "  ";
    std::cout << this->titulo << " ";
    std::cout << "(" << this->duracion << " min)" << std::endl;
}

std::istream &operator>>(std::istream &entrada, Episodio &episodio)
{
    entrada >> episodio.temporada >> episodio.episodio >> episodio.titulo >> episodio.duracion;
    episodio.setTemporada(episodio.temporada);
    episodio.setEpisodio(episodio.episodio);
    episodio.setTitulo(episodio.titulo);
    episodio.setDuracion(episodio.duracion);
    return entrada;
}