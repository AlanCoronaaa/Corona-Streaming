//
// Created by Alan Corona on 6/12/2023.
//

#ifndef CORONASTREAMING_VIDEO_H
#define CORONASTREAMING_VIDEO_H
/*
Archivo: Video.cpp
Autor: Alan Corona
Fecha de creación: 12/06/2023

Descripción:
Este archivo contiene la implementación de la clase Video, que representa un video en el catálogo de videos.
Define los métodos de la clase, incluyendo el constructor predeterminado, el constructor con parámetros,
los métodos de acceso y modificación de los atributos.


#include "Video.h"

// Constructor predeterminado
Video::Video()
        : tipoDeVideo(""), id(0), titulo(""), genero(""), numeroDeCalificaciones(0), calificacion(0.0)
{
}

// Constructor con parámetros
Video::Video(std::string tipoDeVideo, int id, std::string titulo, std::string genero, int numeroDeCalificaciones, float calificacion)
        : tipoDeVideo(tipoDeVideo), id(id), titulo(titulo), genero(genero), numeroDeCalificaciones(numeroDeCalificaciones), calificacion(calificacion)
{
}

// Método de acceso para obtener el tipo de video
std::string Video::getTipoDeVideo() const
{
    return tipoDeVideo;
}

// Método de acceso para obtener el ID del video
int Video::getId() const
{
    return id;
}

// Método de acceso para obtener el título del video
std::string Video::getTitulo() const
{
    return titulo;
}

// Método de acceso para obtener el género del video
std::string Video::getGenero() const
{
    return genero;
}

// Método de acceso para obtener el número de calificaciones del video
int Video::getNumeroDeCalificaciones() const
{
    return numeroDeCalificaciones;
}

// Método de acceso para obtener la calificación del video
float Video::getCalificacion() const
{
    return calificacion;
}

// Método de modificación para establecer el tipo de video
void Video::setTipoDeVideo(std::string tipoDeVideo)
{
    this->tipoDeVideo = tipoDeVideo;
}

// Método de modificación para establecer el ID del video
void Video::setId(int id)
{
    this->id = id;
}

// Método de modificación para establecer el título del video
void Video::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

// Método de modificación para establecer el género del video
void Video::setGenero(std::string genero)
{
    this->genero = genero;
}

// Método de modificación para establecer el número de calificaciones del video
void Video::setNumeroDeCalificaciones(int numeroDeCalificaciones)
{
    this->numeroDeCalificaciones = numeroDeCalificaciones;
}

// Método de modificación para establecer la calificación del video
void Video::setCalificacion(float calificacion)
{
    this->calificacion = calificacion;
}
*/

#include <string>
class Video
{
public:
    Video();
    Video(std::string, int, std::string, std::string, int, float);
    std::string getTipoDeVideo() const;
    int getId() const;
    std::string getTitulo() const;
    std::string getGenero() const;
    int getNumeroDeCalificaciones() const;
    float getCalificacion() const;
    void setTipoDeVideo(std::string);
    void setId(int);
    void setTitulo(std::string);
    void setGenero(std::string);
    void setNumeroDeCalificaciones(int);
    void setCalificacion(float);
    virtual void imprime() = 0;
private:
    std::string tipoDeVideo;
    int id;
    std::string titulo;
    std::string genero;
    int numeroDeCalificaciones;
    float calificacion;
};

#endif //CORONASTREAMING_VIDEO_H
