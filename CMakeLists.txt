cmake_minimum_required(VERSION 3.23)
project(CoronaStreaming)

set(CMAKE_CXX_STANDARD 14)

add_executable(CoronaStreaming main.cpp Episodio.cpp Episodio.h Video.cpp Video.h Catalogo.cpp Catalogo.h Pelicula.cpp Pelicula.h Serie.cpp Serie.h)
