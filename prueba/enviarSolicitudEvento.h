// enviarSolicitudEvento.h

#ifndef ENVIAR_SOLICITUD_EVENTO_H
#define ENVIAR_SOLICITUD_EVENTO_H

#include <iostream>
#include <vector>
#include "estructuras.h"

using namespace std;

// Función para enviar una solicitud de evento.
void enviarSolicitudEvento(vector<SolicitudEvento>& solicitudes, const string& nombreEvento, const string& nombreUsuario, const string& mensaje) {
    SolicitudEvento solicitud;
    solicitud.nombreEvento = nombreEvento;
    solicitud.nombreUsuario = nombreUsuario;
    solicitud.fechaSolicitud = obtenerFechaActual();
    solicitud.mensaje = mensaje;
    solicitud.aprobada = false;

    solicitudes.push_back(solicitud);
    cout << "Solicitud enviada para el evento '" << nombreEvento << "'.\n";
}

#endif // ENVIAR_SOLICITUD_EVENTO_H
