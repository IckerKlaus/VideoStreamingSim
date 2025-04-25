#include "MisClases.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    
    long long int id;
    string nombre, duracion, genero, video;
    float calificacion;
    char opcion;

    do {
        cout << "Ingrese lo que desea hacer." << endl;
        cout << "- Cargar archivo con datos (A)" << endl;
        cout << "- Mostrar peliculas (P)" << endl;
        cout << "- Mostrar series (S)" << endl;
        cout << "- Mostrar serie y episodios (E)" << endl;
        cout << "- Calificar una serie o pelicula (C)" << endl;
        cout << "- Salir del programa (O)" << endl;
        cout << "Tu opcion es: ";
        cin >> opcion;

        cout << endl;

        switch (opcion) {
            case 'A': {
                cout << "Desea cargar una /Pelicula/ o una /Serie/: ";
                cin >> video;
                
                if(video == "Pelicula") {
                    cout << "El ID de la pelicula es [000000]: "; cin >> id;
                    cout << "El nombre de la pelicula es [Example]: "; cin >> nombre;
                    cout << "La duracion de la pelicula es [2h30m]: "; cin >> duracion;
                    cout << "El genero de la pelicula es [Accion]: "; cin >> genero;
                    cout << "La calificacion que otorga a la pelicula es [escala de 1 a 5 donde 5 es la mejor calificación]: "; cin >> calificacion;

                    cout << endl;

                    Pelicula pelicula1(id, nombre, duracion, genero, calificacion);
                    cout << pelicula1 << endl;

                } else if(video == "Serie") {
                    cout << "El ID de la serie es [000000]: "; cin >> id;
                    cout << "El nombre de la serie es [Example]: "; cin >> nombre;
                    cout << "La duracion de la serie es [2h30m]: "; cin >> duracion;
                    cout << "El genero de la serie es [Accion]: "; cin >> genero;
                    cout << "La calificacion que otorga a la serie es [escala de 1 a 5 donde 5 es la mejor calificación]: "; cin >> calificacion;

                    cout << endl;

                    Serie serie1(id, nombre, duracion, genero, calificacion);
                    cout << serie1 << endl;
                }  else {
                    cout << "Error. No se logro identificar si deseaba cargar una /Pelicula/ o una /Serie/." << endl;
                    exit(0);
                }
                break;
            }
            case 'P': {
                Pelicula pelicula1(178294, "Inception", "2h 28m", "Accion", 4.8);
                cout << pelicula1 << endl;
                cout << endl;
                Pelicula pelicula2(172839, "MIB", "1h 38m", "Accion", 5);
                cout << pelicula2 << endl;
                break;
            }

            case 'S': {
                Serie serie1(227854, "Game of Thrones", "1h por episodio", "Accion", 4.7);
                cout << serie1 << endl;
                cout << endl;
                Serie serie2(875961, "House of Dragons", "1h por episodio", "Accion", 4.9);
                cout << serie2 << endl;
                break;
            }

            case 'E': {
                Episodio episodio1("Winter Is Coming", 1, 1, 4.5);
                Episodio episodio2("The Kingsroad", 1, 2, 4.6);
                Episodio episodio3("Lord Snow", 1, 3, 4.8);

                Serie serie1(227854, "Game of Thrones", "1h por episodio", "Accion", 4.7);
                serie1.agregarEpisodio(episodio1);
                serie1.agregarEpisodio(episodio2);
                serie1.agregarEpisodio(episodio3);

                cout << serie1 << endl;            
                break;
            }

            case 'C': {
                cout << "Desea calificar una /Pelicula/ o una /Serie/: ";
                cin >> video;
                
                if(video == "Pelicula") {
                    cout << "El nombre de la pelicula es [Example]: "; cin >> nombre;
                    cout << "La calificacion que otorga a la pelicula es [escala de 1 a 5 donde 5 es la mejor calificación]: "; cin >> calificacion;

                    cout << endl;

                    Pelicula pelicula1(891056, nombre, "NA", "NA", calificacion);
                    cout << pelicula1 << endl;

                } else if(video == "Serie") {
                    cout << "El nombre de la serie es [Example]: "; cin >> nombre;
                    cout << "La calificacion que otorga a la serie es [escala de 1 a 5 donde 5 es la mejor calificación]: "; cin >> calificacion;

                    cout << endl;

                    Serie serie1(321665, nombre, "NA", "NA", calificacion);
                    cout << serie1 << endl;
                } else {
                    cout << "Error. No se logro identificar si deseaba calificar una /Pelicula/ o una /Serie/." << endl;
                    exit(0);
                }
                break;
            }
            
            case 'O': {
                break;
            }

            default: {
                cout << "Opción no válida. Por favor, elija una opción del menú." << endl;
                break;
            }
        }
    } while(opcion != 'O');
    cout << endl;
    cout << "Gracias por su preferencia. Recuerde que el mejor entretenimiento lo tiene esta plataforma." << endl;
    cout << endl;
    exit(0);

    return 0;
}