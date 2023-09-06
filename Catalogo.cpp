//
// Created by Alan Corona on 6/12/2023.
//
#include "Catalogo.h"
#include <fstream>
#include <iostream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <map>

Catalogo::Catalogo()
{
}

Catalogo::Catalogo(std::vector<Video *> videos)
{
    setVideos(videos);
}

std::vector<Video *> Catalogo::getVideos() const
{
    return this->videos;
}

void Catalogo::setVideos(std::vector<Video *> videos)
{
    this->videos = videos;
}

void Catalogo::imprimeVideos(std::string tipoDeVideo, int id, std::string titulo, std::string genero, float calificacionMinima, float calificacionMaxima)
{
    std::cout << "################ CONSULTA ################" << std::endl;
    std::cout << "-------- Parámetros de búsqueda --------" << std::endl;
    if (tipoDeVideo != "cualquiera")
        std::cout << "Tipo de videos.txt : " << (tipoDeVideo == "s" ? "Series" : "Películas") << std::endl;
    if (id != -1)
        std::cout << "ID: " << id << std::endl;
    if (titulo != "cualquiera")
        std::cout << "Título: " << titulo << std::endl;
    if (genero != "cualquiera")
        std::cout << "Género: " << genero << std::endl;
    if (calificacionMinima != -1)
        std::cout << "Calificación mínima: " << calificacionMinima << std::endl;
    if (calificacionMaxima != -1)
        std::cout << "Calificación máxima: " << calificacionMaxima << std::endl;
    std::cout << "--------" << std::endl;
    std::cout << std::endl;
    for (auto video : this->videos)
    {
        if ((tipoDeVideo == "cualquiera" || video->getTipoDeVideo() == tipoDeVideo) &&
            (id == -1 || video->getId() == id) &&
            (titulo == "cualquiera" || video->getTitulo() == titulo) &&
            (genero == "cualquiera" || video->getGenero() == genero) &&
            (calificacionMinima == -1 || video->getCalificacion() >= calificacionMinima) &&
            (calificacionMaxima == -1 || video->getCalificacion() <= calificacionMaxima))
        {
            video->imprime();
            std::cout << std::endl;
        }
    }
    std::cout << "##########################################" << std::endl;
}

void Catalogo::calificaVideo(int id, int calificacion)
{
    for (auto video : this->videos)
    {
        if (video->getId() == id)
        {
            video->setCalificacion((video->getNumeroDeCalificaciones() * video->getCalificacion() + calificacion) / (video->getNumeroDeCalificaciones() + 1));
            video->setNumeroDeCalificaciones(video->getNumeroDeCalificaciones() + 1);
            break;
        }
    }
}

void Catalogo::cargaCatalogo(std::string rutaDelArchivo)
{
    std::ifstream archivo;
    try
    {
        archivo.open(rutaDelArchivo);
        if (!archivo.is_open())
        {
            throw std::runtime_error("[!] No fue posible abrir un archivo.");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        abort();
    }
    std::string tipoDeVideo;
    while (archivo >> tipoDeVideo)
    {
        int id;
        std::string titulo;
        std::string genero;
        int numeroDeCalificaciones;
        float calificacion;
        archivo >> id >> titulo >> genero >> numeroDeCalificaciones >> calificacion;
        if (tipoDeVideo == "p")
        {
            int duracion;
            archivo >> duracion;
            Pelicula * pelicula = new Pelicula(tipoDeVideo, id, titulo, genero, numeroDeCalificaciones, calificacion, duracion);
            this->videos.push_back(pelicula);
        }
        else // Se asume serie ("s")
        {
            int cantidadDeCapitulos;
            archivo >> cantidadDeCapitulos;
            std::map<std::pair<int, int>, Episodio> episodios;
            for (int i = 0; i < cantidadDeCapitulos; ++i)
            {
                Episodio episodio;
                archivo >> episodio;
                episodios[{episodio.getTemporada(), episodio.getEpisodio()}] = episodio;
            }
            Serie * serie = new Serie(tipoDeVideo, id, titulo, genero, numeroDeCalificaciones, calificacion, episodios);
            this->videos.push_back(serie);
        }
    }
    archivo.close();
}