//
// Created by Alan Corona on 6/12/2023.
//

#include "Video.h"

Video::Video()
        : tipoDeVideo(""), id(0), titulo(""), genero(""), numeroDeCalificaciones(0), calificacion(0.0)
{
}

Video::Video(std::string tipoDeVideo, int id, std::string titulo, std::string genero, int numeroDeCalificaciones, float calificacion)
        : tipoDeVideo(tipoDeVideo), id(id), titulo(titulo), genero(genero), numeroDeCalificaciones(numeroDeCalificaciones), calificacion(calificacion)
{
}

std::string Video::getTipoDeVideo() const
{
    return tipoDeVideo;
}

int Video::getId() const
{
    return id;
}

std::string Video::getTitulo() const
{
    return titulo;
}

std::string Video::getGenero() const
{
    return genero;
}

int Video::getNumeroDeCalificaciones() const
{
    return numeroDeCalificaciones;
}

float Video::getCalificacion() const
{
    return calificacion;
}

void Video::setTipoDeVideo(std::string tipoDeVideo)
{
    this->tipoDeVideo = tipoDeVideo;
}

void Video::setId(int id)
{
    this->id = id;
}

void Video::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

void Video::setGenero(std::string genero)
{
    this->genero = genero;
}

void Video::setNumeroDeCalificaciones(int numeroDeCalificaciones)
{
    this->numeroDeCalificaciones = numeroDeCalificaciones;
}

void Video::setCalificacion(float calificacion)
{
    this->calificacion = calificacion;
}