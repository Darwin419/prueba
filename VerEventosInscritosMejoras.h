// VerEventosInscritos.h
#ifndef VER_EVENTOS_INSCRITOS_H
#define VER_EVENTOS_INSCRITOS_H

#include <iostream>
#include <vector>
#include <string>
#include "estructuras.h"  // Asumiendo que las estructuras están en este archivo

using namespace std;

// La funcion verEventosInscritos muestra los eventos en los que un usuario esta inscrito.
// La funcion permite al usuario seleccionar un evento para ver los detalles de los inscritos.
// Ahora incluye una opción para salir del menú sin realizar una selección.
void verEventosInscritos(const vector<Evento>& eventos, const string& usuarioActual) {
    if (eventos.empty()) {
        cout << "No hay eventos disponibles.\n";
        cout << "Presione Enter para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    cout << "Seleccione el número del evento para ver los inscritos o '0' para salir:\n";
    for (int i = 0; i < eventos.size(); ++i) {
        cout << i + 1 << ". " << eventos[i].nombre << "\n";
    }
    cout << "0. Salir\n";

    int numEvento;
    cin >> numEvento;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Si el usuario selecciona '0', sale de la función.
    if (numEvento == 0) {
        return;
    }

    if (numEvento < 1 || numEvento > eventos.size()) {
        cout << "Numero de evento no valido.\n";
    } else {
        const Evento& eventoSeleccionado = eventos[numEvento - 1];
        cout << "Personas inscritas en el evento '" << eventoSeleccionado.nombre << "':\n";
        if (eventoSeleccionado.inscritos.empty()) {
            cout << "No hay personas inscritas en este evento.\n";
        } else {
            for (const string& inscrito : eventoSeleccionado.inscritos) {
                cout << "- " << inscrito << "\n";
            }
        }
    }

    cout << "Presione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

#endif // VER_EVENTOS_INSCRITOS_H


//git commit -m "Mejoras en verEventosInscritos (opción de salida)"
