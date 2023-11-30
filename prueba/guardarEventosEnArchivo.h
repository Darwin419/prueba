// guardarEventosEnArchivo.h

#ifndef GUARDAR_EVENTOS_EN_ARCHIVO_H
#define GUARDAR_EVENTOS_EN_ARCHIVO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "estructuras.h" // Asumiendo que las estructuras están en este archivo

using namespace std;

// Función para guardar la lista de eventos en un archivo de texto.
void guardarEventosEnArchivo(const vector<Evento>& eventos, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar eventos.\n";
        return;
    }

    for (const Evento& evento : eventos) {
        archivo << "Nombre: " << evento.nombre << "\n";
        archivo << "Fecha: " << evento.fecha << "\n";
        archivo << "Lugar: " << evento.lugar << "\n";
        archivo << "Descripción: " << evento.descripcion << "\n";
        archivo << "Inscritos: ";
        
        for (const string& inscrito : evento.inscritos) {
            archivo << inscrito << ", ";
        }
        
        archivo << "\n\n";
    }

    archivo.close();
    cout << "Eventos guardados exitosamente en el archivo: " << nombreArchivo << "\n";
}

#endif // GUARDAR_EVENTOS_EN_ARCHIVO_H
