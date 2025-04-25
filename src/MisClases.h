#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Video {
private:
    long long int id;
    string nombre;
    string duracion;
    string genero;
    float calificacion;

public:
    Video() : id(0), nombre("No definido"), duracion("0h 0m"), genero("No definido"), calificacion(0) {}

    Video(long long int id, string nombre, string duracion, string genero, float calificacion) : 
        id(id), nombre(nombre), duracion(duracion), genero(genero), calificacion(calificacion) {}

    long long int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getDuracion() const { return duracion; }
    string getGenero() const { return genero; }
    float getCalificacion() const { return calificacion; }

    virtual void printInformacion() const = 0;

    friend ostream& operator<<(ostream& out, const Video& video) {
        video.printInformacion();
        return out;
    }

    virtual ~Video() = default;
};

class Pelicula : public Video {
public:
    Pelicula() : Video() {}

    Pelicula(long long int id, string nombre, string duracion, string genero, float calificacion) : 
        Video(id, nombre, duracion, genero, calificacion) {}

    void printInformacion() const override {
        cout << "Película -" << endl;
        cout << "ID: " << getId() << endl;
        cout << "Nombre: " << getNombre() << endl;
        cout << "Duración: " << getDuracion() << endl;
        cout << "Género: " << getGenero() << endl;
        cout << "Calificación [1 a 5]: " << getCalificacion() << endl;
    }
};

class Episodio {
private:
    string titulo;
    int temporada;
    int numeroEpisodio;
    float calificacionEpisodio;

public:
    Episodio() : titulo("No definido"), temporada(0), numeroEpisodio(0), calificacionEpisodio(0) {}

    Episodio(string titulo, int temporada, int numeroEpisodio, float calificacionEpisodio) :
        titulo(titulo), temporada(temporada), numeroEpisodio(numeroEpisodio), calificacionEpisodio(calificacionEpisodio) {}

    string getTitulo() const { return titulo; }
    int getTemporada() const { return temporada; }
    int getNumeroEpisodio() const { return numeroEpisodio; }
    float getCalificacionEpisodio() const { return calificacionEpisodio; }

    void printInformacion() const {
        cout << "Título: " << titulo << endl;
        cout << "Temporada: " << temporada << endl;
        cout << "Episodio número: " << numeroEpisodio << endl;
        cout << "Calificación: " << calificacionEpisodio << endl;
    }

    friend ostream& operator<<(ostream& out, const Episodio& episodio) {
        episodio.printInformacion();
        return out;
    }
};

class Serie : public Video {
private:
    vector<Episodio> episodios;

public:
    Serie() : Video() {}

    Serie(long long int id, string nombre, string duracion, string genero, float calificacion) : 
        Video(id, nombre, duracion, genero, calificacion) {}

    void agregarEpisodio(const Episodio& episodio) {
        episodios.push_back(episodio);
    }

    void printInformacion() const override {
        cout << "Serie -" << endl;
        cout << "ID: " << getId() << endl;
        cout << "Nombre: " << getNombre() << endl;
        cout << "Duración: " << getDuracion() << endl;
        cout << "Género: " << getGenero() << endl;
        cout << "Calificación [1 a 5]: " << getCalificacion() << endl;
        cout << endl;
        for (const auto& episodio : episodios) {
            cout << episodio << endl;
        }
    }
};
