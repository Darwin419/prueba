// funcionesClaveUsuarios.h

#ifndef FUNCIONES_CLAVE_USUARIOS_H
#define FUNCIONES_CLAVE_USUARIOS_H

#include <iostream>
#include <vector>
#include "estructuras.h"  

using namespace std;

// Función para inscribirse en un evento.
void inscribirseEnEvento(vector<Evento>& eventos, const string& usuarioActual) {
    if (eventos.empty()) {
        // Si no hay eventos, informamos al usuario y salimos de la función.
        cout << "No hay eventos disponibles para inscribirse.\n";
        cout << "Presione Enter para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    int opcion;
    cout << "Como desea buscar el evento para inscribirse?\n";
    cout << "1. Listar todos los eventos\n";
    cout << "2. Buscar evento por similitud\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion o '0' para salir: ";
    cin >> opcion;

    // Si el usuario elige salir, terminamos la funcion.
    if (opcion == 0) {
        return;
    }

    vector<Evento*> eventosEncontrados;
    switch (opcion) {
        case 1:
            // Listamos todos los eventos disponibles.
            for (Evento& e : eventos) {
                eventosEncontrados.push_back(&e);
            }
            break;
        case 2:
            // Buscamos eventos por similitud de nombre.
            eventosEncontrados = ObtenerEventosPorSimilitud(eventos);
            break;
        default:
            cout << "Opcion no valida.\n";
            return;
    }

    if (eventosEncontrados.empty()) {
        cout << "No se encontraron eventos.\n";
        return;
    }

    cout << "Seleccione el numero del evento al que desea inscribirse o '0' para salir:\n";
    for (int i = 0; i < eventosEncontrados.size(); ++i) {
        cout << i + 1 << ". " << eventosEncontrados[i]->nombre << "\n";
    }
    cout << "0. Salir\n";

    int numEvento;
    cin >> numEvento;

    if (numEvento == 0) {
        return;
    } else if (numEvento < 1 || numEvento > eventosEncontrados.size()) {
        cout << "Numero de evento no valido.\n";
        return;
    }

    Evento* eventoSeleccionado = eventosEncontrados[numEvento - 1];
    // Verificamos si el usuario ya está inscrito en el evento.
    if (find(eventoSeleccionado->inscritos.begin(), eventoSeleccionado->inscritos.end(), usuarioActual) != eventoSeleccionado->inscritos.end()) {
        cout << "Ya estas inscrito en este evento.\n";
    } else {
        // Si no está inscrito, lo añadimos a la lista de inscritos.
        eventoSeleccionado->inscritos.push_back(usuarioActual);
        cout << "Inscripcion exitosa en el evento: " << eventoSeleccionado->nombre << "\n";
    }

    cout << "Presione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Función para ver los eventos en los que un usuario está inscrito.
void verEventosInscritos(const vector<Evento>& eventos, const string& usuarioActual) {
    // Buscamos los eventos en los que el usuario está inscrito.
    vector<Evento> eventosInscrito;
    for (const Evento& evento : eventos) {
        if (find(evento.inscritos.begin(), evento.inscritos.end(), usuarioActual) != evento.inscritos.end()) {
            eventosInscrito.push_back(evento);
        }
    }

    if (eventosInscrito.empty()) {
        cout << "No estas inscrito en ningun evento.\n";
    } else {
        cout << "Eventos en los que estás inscrito:\n";
        for (const Evento& evento : eventosInscrito) {
            cout << "- " << evento.nombre << "\n";
        }
    }

    cout << "Presione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Menú de usuario que llama a las funciones anteriores.
void menuUsuario(vector<Evento>& eventos, const string& usuarioActual) {
    while (true) {
        int opcion;
        cout << "Menú de Usuario\n";
        cout << "1. Inscribirse en un evento\n";
        cout << "2. Ver eventos inscritos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                inscribirseEnEvento(eventos, usuarioActual);
                break;
            case 2:
                verEventosInscritos(eventos, usuarioActual);
                break;
            case 0:
                return;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    }
}

#endif // FUNCIONES_CLAVE_USUARIOS_H

//git commit -m "Commit 7: Comentarios explicativos en funciones clave para usuarios"
