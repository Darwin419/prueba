// verSolicitudesDeEvento.h

#ifndef VER_SOLICITUDES_DE_EVENTO_H
#define VER_SOLICITUDES_DE_EVENTO_H

#include <iostream>
#include <vector>
#include "estructuras.h"

using namespace std;

// Función para ver las solicitudes de un evento.
void verSolicitudesDeEvento(vector<SolicitudEvento>& solicitudes, const string& nombreEvento) {
    cout << "Solicitudes pendientes para el evento '" << nombreEvento << "':\n";
    for (const SolicitudEvento& solicitud : solicitudes) {
        if (solicitud.nombreEvento == nombreEvento) {
            cout << "Usuario: " << solicitud.nombreUsuario << "\n";
            cout << "Fecha de solicitud: " << solicitud.fechaSolicitud << "\n";
            cout << "Mensaje: " << solicitud.mensaje << "\n";
            cout << "Estado: " << (solicitud.aprobada ? "Aprobada" : "Pendiente") << "\n";
            cout << "----------------------------------\n";
        }
    }
}

#endif // VER_SOLICITUDES_DE_EVENTO_H
