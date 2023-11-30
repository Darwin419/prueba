// verEventosInscritos.h

#ifndef VER_EVENTOS_INSCRITOS_H
#define VER_EVENTOS_INSCRITOS_H

#include <iostream>
#include <vector>
#include "estructuras.h"

using namespace std;

// Función para mostrar los eventos en los que el usuario está inscrito.
void verEventosInscritos(const vector<Evento>& eventos, const string& usuarioActual) {
    if (eventos.empty()) {
        cout << "No hay eventos disponibles.\n";
        cout << "Presione Enter para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    cout << "Eventos en los que estás inscrito:\n";
    bool inscritoEnAlMenosUno = false;  // Variable para verificar si el usuario está inscrito en al menos un evento.

    for (const Evento& evento : eventos) {
        if (find(evento.inscritos.begin(), evento.inscritos.end(), usuarioActual) != evento.inscritos.end()) {
            cout << "- " << evento.nombre << "\n";
            inscritoEnAlMenosUno = true;
        }
    }

    if (!inscritoEnAlMenosUno) {
        cout << "No estás inscrito en ningún evento.\n";
    }

    cout << "Presione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

#endif // VER_EVENTOS_INSCRITOS_H

//git commit -m "Commit 8: Refactorización de verEventosInscritos para mejorar claridad"
