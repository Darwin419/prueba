// buscarEventosPorSimilitud.h

#ifndef BUSCAR_EVENTOS_POR_SIMILITUD_H
#define BUSCAR_EVENTOS_POR_SIMILITUD_H

#include <iostream>
#include <vector>
#include "estructuras.h"  // Asumiendo que las estructuras están en este archivo

using namespace std;

// Función para buscar eventos por similitud en el nombre.
// Esta función permite al usuario ingresar una cadena de búsqueda y encuentra eventos cuyo nombre contiene esa cadena.
// Devuelve un vector de punteros a eventos que coinciden con la búsqueda.
vector<Evento*> buscarEventosPorSimilitud(const vector<Evento>& eventos, const string& cadenaBusqueda) {
    vector<Evento*> eventosEncontrados;

    for (const Evento& evento : eventos) {
        // Verificamos si el nombre del evento contiene la cadena de búsqueda (ignorando mayúsculas y minúsculas).
        if (stringContains(evento.nombre, cadenaBusqueda)) {
            eventosEncontrados.push_back(const_cast<Evento*>(&evento));
        }
    }

    return eventosEncontrados;
}

// Función auxiliar para verificar si una cadena contiene otra (ignorando mayúsculas y minúsculas).
bool stringContains(const string& str, const string& substr) {
    string strLower = str;
    string substrLower = substr;

    // Convertimos ambas cadenas a minúsculas antes de realizar la búsqueda.
    transform(strLower.begin(), strLower.end(), strLower.begin(), ::tolower);
    transform(substrLower.begin(), substrLower.end(), substrLower.begin(), ::tolower);

    // Realizamos la búsqueda.
    return strLower.find(substrLower) != string::npos;
}

#endif // BUSCAR_EVENTOS_POR_SIMILITUD_H
