
# Corona Streaming

## Description

Corona Streaming is an on-demand video management system developed in C++ using Object-Oriented Programming (OOP) principles. The system allows users to manage a collection of videos, including movies and series, and offers functionalities such as adding, deleting, searching videos, and displaying their average ratings.



## Features

- **Video Management**: Manage two types of videos: movies and series.
- **Ratings**: Videos have an average rating on a scale from 1 to 5.
- **Series and Episodes**: Series consist of episodes, each with its own title and season.
- **Flexibility**: Utilizes inheritance and polymorphism to create specialized classes, allowing for a modular and extensible structure.

## Main Classes

- **Video**: Abstract base class that represents a generic video.
- **Movies**: Inherits from Video and adds specific attributes such as director and release year.
- **Series**: Inherits from Video and adds specific attributes such as the number of seasons and episodes.
- **Episode**: Derived class from Video that represents an episode of a series.
- **Catalog**: Class that manages a collection of videos using a vector of pointers to Video objects.

## Requirements

- **C++ Compiler**: Requires a compiler compatible with C++11 or higher.
- **Operating System**: The code is developed and tested in a Linux environment, but it should be compatible with Windows and macOS with appropriate modifications.

## Usage Instructions

1. **Compilation**: To compile the project, use the following command in the terminal:
   ```bash
   g++ main.cpp Video.cpp Pelicula.cpp Serie.cpp Episodio.cpp -o CoronaStreaming
   ```
2. **Execution**: Once compiled, run the program with:
   ```bash
   ./CoronaStreaming
   ```

## Project Structure

The project is organized as follows:

```
Corona-Streaming/
│
├── Episodio.cpp
├── Episodio.h
├── Pelicula.cpp
├── Pelicula.h
├── Serie.cpp
├── Serie.h
├── Video.cpp
├── Video.h
├── main.cpp
├── videos.txt
└── README.md
```

- **main.cpp**: Entry point of the program.
- **Video.h/Video.cpp**: Base definition and functionality for videos.
- **Pelicula.h/Pelicula.cpp**: Specific functionality for movies.
- **Serie.h/Serie.cpp**: Specific functionality for series.
- **Episodio.h/Episodio.cpp**: Specific functionality for series episodes.
- **videos.txt**: Input file that contains the list of videos with their respective ratings.

## Potential Errors

- **Memory Errors**: May occur if there is improper pointer management.
- **Invalid Data**: Empty titles or negative durations could cause unexpected behavior.
- **Issues Reading videos.txt**: Incorrect format or poorly structured files could cause runtime errors.

## Contributions

This project was made by Alan Corona López as part of the Object-Oriented Programming course. Suggestions and improvements are welcome through pull requests on this repository.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.
```
