// menuUsuario.h

#ifndef MENU_USUARIO_H
#define MENU_USUARIO_H

#include <iostream>
#include "inscribirseEnEvento.h"
#include "verEventosInscritos.h"

using namespace std;

// Funcion para mostrar el menu principal del usuario.
// Permite al usuario seleccionar entre inscribirse en un evento o ver sus eventos inscritos.
void menuUsuario(vector<Evento>& eventos, const string& usuarioActual) {
    while (true) {
        int opcion;
        cout << "Menu de Usuario:\n";
        cout << "1. Inscribirse en un evento\n";
        cout << "2. Ver eventos inscritos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 0:
                return;
            case 1:
                inscribirseEnEvento(eventos, usuarioActual);
                break;
            case 2:
                verEventosInscritos(eventos, usuarioActual);
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    }
}

#endif // MENU_USUARIO_H

//git commit -m "Commit 10: Finalización y revisión del menú de usuario"
