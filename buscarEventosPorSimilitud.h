// buscarEventosPorSimilitud.h

#ifndef BUSCAR_EVENTOS_POR_SIMILITUD_H
#define BUSCAR_EVENTOS_POR_SIMILITUD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "estructuras.h"  

using namespace std;

// La funcion buscarEventosPorSimilitud permite al usuario buscar eventos que coincidan
// con un termino de busqueda. Se implementa una busqueda avanzada para encontrar eventos
// similares en nombre o descripcion.
vector<Evento*> buscarEventosPorSimilitud(const vector<Evento>& eventos, const string& terminoBusqueda) {
    vector<Evento*> eventosEncontrados;

    for (const Evento& e : eventos) {
        // Convertir nombres y descripciones a minusculas para una búsqueda insensible a mayusculas.
        string nombreMinuscula = e.nombre;
        transform(nombreMinuscula.begin(), nombreMinuscula.end(), nombreMinuscula.begin(), ::tolower);
        string descripcionMinuscula = e.descripcion;
        transform(descripcionMinuscula.begin(), descripcionMinuscula.end(), descripcionMinuscula.begin(), ::tolower);

        // Buscar el termino de búsqueda en nombre o descripcion.
        if (nombreMinuscula.find(terminoBusqueda) != string::npos || descripcionMinuscula.find(terminoBusqueda) != string::npos) {
            eventosEncontrados.push_back(const_cast<Evento*>(&e));  // Usamos const_cast para quitar la constante y agregarlo al resultado.
        }
    }

    return eventosEncontrados;
}

#endif // BUSCAR_EVENTOS_POR_SIMILITUD_H

//git commit -m "Commit 9: Implementación de búsqueda avanzada en buscarEventosPorSimilitud
//En este commit, se ha implementado una búsqueda avanzada en la función buscarEventosPorSimilitud. Ahora, los usuarios pueden buscar eventos por similitud en nombre o descripción, lo que mejora la funcionalidad de búsqueda en el sistema."
