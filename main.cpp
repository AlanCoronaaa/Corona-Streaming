
#include <iostream>
#include <fstream>
#include "Catalogo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdelete-abstract-non-virtual-dtor"
using namespace std;

void imprimeMenu()
{
    cout << "|-----------[͇̿C͇̿O͇̿R͇̿O͇̿N͇̿A͇̿-͇̿S͇̿T͇̿R͇̿E͇̿A͇̿M͇̿I͇̿N͇̿G͇̿]---------|" << endl;
    cout << "|  0. SALIR                                             |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  1. Calificar un video                                |" << endl;
    cout << "|  2. Consultar series                                  |" << endl;
    cout << "|  3. Consultar películas                               |" << endl;
    cout << "|  4. Consultar títulos con una calificacion >= 4       |" << endl;
    cout << "|  5. Realizar una consulta compleja                    |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
}

void leerClick()
{
    string basura;
    cout << "[!] Presione ENTER para continuar ";
    cin.ignore();
    while (true)
    {
        if (cin.get() == '\n')
        {
            break;
        }
    }
}

void limpiaPantalla()
{
    system("clear");
}

string aplicacion()
{
    Catalogo netflix;
    netflix.cargaCatalogo("/videos.txt");

    bool salir = false;
    limpiaPantalla();
    while (!salir)
    {
        imprimeMenu();
        cout << endl;

        int opcion;
        cout << "Opción: ";
        cin >> opcion;

        int calificacion;
        std::string tipoDeVideo = "cualquiera";
        int id = -1;
        std::string titulo = "cualquiera";
        std::string genero = "cualquiera";
        float calificacionMinima = -1;
        float calificacionMaxima = -1;

        string opcionBooleana;

        switch (opcion)
        {
            case 0:
                limpiaPantalla();
                salir = true;
                break;
            case 1:
                limpiaPantalla();
                cout << "Introduzca el ID del título que desea calificar: ";
                cin >> id;
                cout << endl;
                cout << "Introduzca la calificación que le desea asignar: ";
                cin >> calificacion;
                cout << endl;
                if (calificacion < 1 || 5 < calificacion)
                {
                    cout << "[!] Calificación inválida" << endl;
                    cout << endl;
                    leerClick();
                    break;
                }
                netflix.calificaVideo(id, calificacion);
                leerClick();
                break;
            case 2:
                limpiaPantalla();
                netflix.imprimeVideos("s", -1, "cualquiera", "cualquiera", -1, -1);
                cout << endl;
                leerClick();
                break;
            case 3:
                limpiaPantalla();
                netflix.imprimeVideos("p", -1, "cualquiera", "cualquiera", -1, -1);
                cout << endl;
                leerClick();
                break;
            case 4:
                limpiaPantalla();
                netflix.imprimeVideos("cualquiera", -1, "cualquiera", "cualquiera", 4, -1);
                cout << endl;
                leerClick();
                break;
            case 5:
                limpiaPantalla();

                cout << "¿Desea restringir su búsqueda por tipo de videos.txt? [s / n]: ";
                cin >> opcionBooleana;
                cout << endl;
                if (opcionBooleana != "s" && opcionBooleana != "n")
                {
                    cout << endl;
                    cout << "[!] Opción inválida" << endl;
                    cout << endl;
                    leerClick();
                    break;
                }
                if (opcionBooleana == "s")
                {
                    cout << "Tipo de videos.txt [s := Series / p := Películas]: ";
                    cin >> tipoDeVideo;
                    if (tipoDeVideo != "s" && tipoDeVideo != "p")
                    {
                        cout << endl;
                        cout << "[!] Opción inválida" << endl;
                        cout << endl;
                        leerClick();
                        break;
                    }
                    cout << endl;
                }

                cout << "¿Desea restringir su búsqueda por ID? [s / n]: ";
                cin >> opcionBooleana;
                cout << endl;
                if (opcionBooleana != "s" && opcionBooleana != "n")
                {
                    cout << endl;
                    cout << "[!] Opción inválida" << endl;
                    cout << endl;
                    leerClick();
                    break;
                }
                if (opcionBooleana == "s")
                {
                    cout << "ID: ";
                    cin >> id;
                    cout << endl;
                }

                cout << "¿Desea restringir su búsqueda por título? [s / n]: ";
                cin >> opcionBooleana;
                cout << endl;
                if (opcionBooleana != "s" && opcionBooleana != "n")
                {
                    cout << endl;
                    cout << "[!] Opción inválida" << endl;
                    cout << endl;
                    leerClick();
                    break;
                }
                if (opcionBooleana == "s")
                {
                    cout << "Título: ";
                    cin >> titulo;
                    cout << endl;
                }

                cout << "¿Desea restringir su búsqueda por género? [s / n]: ";
                cin >> opcionBooleana;
                cout << endl;
                if (opcionBooleana != "s" && opcionBooleana != "n")
                {
                    cout << endl;
                    cout << "[!] Opción inválida" << endl;
                    cout << endl;
                    leerClick();
                    break;
                }
                if (opcionBooleana == "s")
                {
                    cout << "Género: ";
                    cin >> genero;
                    cout << endl;
                }

                cout << "¿Desea restringir su búsqueda por calificación mínima? [s / n]: ";
                cin >> opcionBooleana;
                cout << endl;
                if (opcionBooleana != "s" && opcionBooleana != "n")
                {
                    cout << endl;
                    cout << "[!] Opción inválida" << endl;
                    cout << endl;
                    leerClick();
                    break;
                }
                if (opcionBooleana == "s")
                {
                    cout << "Calificación mínima: ";
                    cin >> calificacionMinima;
                    cout << endl;
                }

                cout << "¿Desea restringir su búsqueda por calificación máxima? [s / n]: ";
                cin >> opcionBooleana;
                cout << endl;
                if (opcionBooleana != "s" && opcionBooleana != "n")
                {
                    cout << endl;
                    cout << "[!] Opción inválida" << endl;
                    cout << endl;
                    leerClick();
                    break;
                }
                if (opcionBooleana == "s")
                {
                    cout << "Calificación máxima: ";
                    cin >> calificacionMaxima;
                    cout << endl;
                }
                limpiaPantalla();
                netflix.imprimeVideos(tipoDeVideo, id, titulo, genero, calificacionMinima, calificacionMaxima);
                cout << endl;
                leerClick();
                break;
            default:
                cout << endl;
                cout << "[!] Opción inválida" << endl;
                cout << endl;
                leerClick();
        }
        limpiaPantalla();
    }
    cout << "Hasta luego. ¡Vuelve pronto!" << endl; // Agrega el mensaje antes de finalizar

    return {};
}

int main()
{
    std::ifstream inputFile("videos.txt");
    if (!inputFile) {
        std::cerr << "[!] No fue posible abrir el archivo." << std::endl;
        return 1;
    }

    std::vector<Video*> videos;

    // Leer datos del archivo y crear instancias de Video, Episodio o Pelicula

    // Ejemplo de lectura de datos:
    std::string line;
    while (std::getline(inputFile, line)) {
        // Procesar cada línea del archivo y crear instancias de Video, Episodio o Pelicula
        // Agregar las instancias a la lista de videos
    }

    // Cerrar el archivo después de leer los datos
    inputFile.close();

    // Realizar operaciones con los objetos de Video

    // Ejemplo de impresión de información de los videos:
    for (const auto& video : videos) {
        video->imprime();
    }

    // Liberar memoria de los objetos creados
    for (const auto& video : videos) {
        delete video;
    }
// Otra Forma de imprimir el catalogo
    Catalogo catalogo;
    catalogo.cargaCatalogo("videos.txt");

    aplicacion();
    return 0;
}
//#pragma clang diagnostic pop es específico del compilador Clang y puede no ser compatible con otros compiladores de C++.
// Además, su uso debe ser cauteloso, ya que desactivar advertencias del compilador puede ocultar problemas o errores potenciales en el código.
// Se recomienda utilizar las advertencias del compilador de manera adecuada y abordar los problemas señalados por ellas.

#pragma clang diagnostic pop