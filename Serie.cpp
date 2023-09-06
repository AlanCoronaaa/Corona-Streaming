//
// Created by Alan Corona on 6/12/2023.
//

#include "Serie.h"
#include <iostream>

Serie::Serie()
{
}

Serie::Serie(std::string tipoDeVideo, int id, std::string titulo, std::string genero, int numeroDeCalificaciones, float calificacion, std::map<std::pair<int, int>, Episodio> episodios) : Video(tipoDeVideo, id, titulo, genero, numeroDeCalificaciones, calificacion)
{
    this->setEpisodios(episodios);
}

std::map<std::pair<int, int>, Episodio> Serie::getEpisodios() const
{
    return this->episodios;
}

void Serie::setEpisodios(std::map<std::pair<int, int>, Episodio> episodios)
{
    this->episodios = episodios;
}

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

void Serie::imprime()
{
    std::cout << "---- " << this->getTitulo() << " (" << this->getId() << ") ----" << std::endl;
    std::cout << "Género: " << this->getGenero() << std::endl;
    std::cout << "Calificación : " << this->getCalificacion() << std::endl;
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