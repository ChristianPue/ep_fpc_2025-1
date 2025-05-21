#include <iostream>
#include <vector>
#include <regex>
using namespace std;

class Jugador
{
public:
    Jugador() { nombre = ""; anotaciones = 0; }
    ~Jugador() {}

    void ingresar_nombre(string nombre) {
        this->nombre = nombre;
    }
    void ingresar_anotaciones(size_t anotaciones) {
        this->anotaciones = anotaciones;
    }

    size_t get_anotaciones() {
        return anotaciones;
    }

private:
    string nombre;
    size_t anotaciones;
};

class Enfrentamiento
{
public:
    Enfrentamiento() { j1 = Jugador(); j2 = Jugador(); }
    ~Enfrentamiento() {}

    void agregar_enfrentamiento(Jugador j1, Jugador j2) {
        this->j1 = j1;
        this->j2 = j2;
    }

private:
    Jugador j1, j2;
};


Jugador extraerDatos(const std::string& entrada) {
    Jugador jugador = Jugador();
    size_t guionPos = entrada.find('-');
    std::string nombre = entrada.substr(0, guionPos);
    int anotaciones = std::stoi(entrada.substr(guionPos + 1));

    jugador.ingresar_nombre(nombre);
    jugador.ingresar_anotaciones(anotaciones);

    return jugador;
}
void registrar_torneo() {
    bool salir = false;
    
    // 1. Ingresa el nombre del torneo
    string nombre_torneo;
    cout << "Ingresa el nombre del torneo: "; cin >> nombre_torneo;

    // 2. Ingresa la cantidad de jugadores (0 < N < 42)
    size_t cant_equipos;
    do
    {
        cout << "Ingresa la cantidad de jugadores: "; cin >> cant_equipos;

        if (cant_equipos > 0 && cant_equipos < 42 && cant_equipos % 2 == 0) { break; }
        else { cout << "Error: (0 < N < 42) y el numero NO debe ser impar." << endl; }

    } while (true);

    // 3. Ingresa los nombres de los jugadores (2 <= nombre <= 25)
    string nombres_jugadores;
    for (size_t i = 0; i < cant_equipos; i++)
    {
        string nombre;
        do
        {
            cout << "Ingresa los nombre del jugador " << i + 1 << ": "; cin >> nombre;

            if (nombre.size() >= 2 && nombre.size() <= 25) { break; }
            else { cout << "Error: (2 <= nombre <= 25)" << endl; }

        } while (true);
    }
    
    // 4. Ingresa la cantidad de enfrentamientos (0 < cant_enfrentamientos < 20)
    size_t cant_enfrentamientos;
    do
    {
        cout << "Ingresa la cantidad de enfrentamientos: "; cin >> cant_enfrentamientos;

        if (cant_enfrentamientos > 0 && cant_enfrentamientos < 20) { break; }
        else { cout << "Error: (0 < cant_enfrentamientos < 20)" << endl; }

    } while (true);

    // 5. Ingresa los enfrentamientos
    vector<Enfrentamiento> enfrentamientos;
    for (size_t i = 0; i < cant_enfrentamientos; i++)
    {
        string d; Enfrentamiento e = Enfrentamiento();
        do
        {
            cout << "Ingresa el enfrentamiento (formato: [Jugador1]–[anotaciones]@[Jugador2]-[anotaciones]) " << i + 1 << ": "; cin >> d;

            size_t arrobaPos = d.find('@');
            Jugador j1 = extraerDatos(d.substr(0, arrobaPos));
            Jugador j2 = extraerDatos(d.substr(arrobaPos + 1));

            if () { ; }

        } while (true);
    }
}

int main()
{
    bool salir = false;

    while (salir == false) {
        
        size_t opc;
        cout << "::::: Programa Registrador de Torneos de Tenis :::::" << endl;
        cout << "1. Ingresa el nombre del torneo." << endl;
        cout << "2. Ingresa la cantidad de equipos y" << endl;
        cout << "   tambien los nombres de los equipos." << endl;
        cout << "3. Ingresa la cantidad de enfrentamientos y" << endl;
        cout << "4. tambien los resultados de los enfrentamientos." << endl;
        cout << "Respuesta:";
    }
}