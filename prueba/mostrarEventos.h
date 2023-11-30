// mostrarEventos.h

#ifndef MOSTRAR_EVENTOS_H
#define MOSTRAR_EVENTOS_H

#include <iostream>
#include <vector>
#include "estructuras.h"  // Asumiendo que las estructuras están en este archivo

using namespace std;

// Función para mostrar la lista de eventos disponibles.
void mostrarEventos(const vector<Evento>& eventos) {
    if (eventos.empty()) {
        cout << "No hay eventos disponibles para mostrar.\n";
    } else {
        cout << "Lista de eventos disponibles:\n";
        for (const Evento& evento : eventos) {
            cout << "Nombre: " << evento.nombre << "\n";
            cout << "Fecha: " << evento.fecha << "\n";
            cout << "Lugar: " << evento.lugar << "\n";
            cout << "Descripción: " << evento.descripcion << "\n";
            cout << "Cupo: " << evento.cupo << "\n";
            cout << "Inscritos: " << evento.inscritos.size() << "\n";
            cout << "--------------------------\n";
        }
    }
}

#endif // MOSTRAR_EVENTOS_H
