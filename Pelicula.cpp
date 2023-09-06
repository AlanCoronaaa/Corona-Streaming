//
// Created by Alan Corona on 6/12/2023.
//
#include "Pelicula.h"
#include <iostream>
// Constructor predeterminado

Pelicula::Pelicula()
        : Video(), duracion(0)
{
}
// Constructor con parámetros

Pelicula::Pelicula(const std::string& tipoDeVideo, int id, const std::string& titulo, const std::string& genero, int numeroDeCalificaciones, float calificacion, int duracion)
        : Video(tipoDeVideo, id, titulo, genero, numeroDeCalificaciones, calificacion), duracion(duracion)
{
}
// Método de acceso para obtener la duración de la película

int Pelicula::getDuracion() const
{
    return duracion;
}
// Método de modificación para establecer la duración de la película

void Pelicula::setDuracion(int duracion)
{
    this->duracion = duracion;
}
// Método para imprimir los detalles de la película

void Pelicula::imprime()
{
    std::cout << "---- " << getTitulo() << " (" << getId() << ") ----" << std::endl;
    std::cout << "Género: " << getGenero() << std::endl;
    std::cout << "Calificación: " << getCalificacion() << std::endl;
    std::cout << "Duración: " << duracion << std::endl;
    std::cout << "----" << std::endl;
}
