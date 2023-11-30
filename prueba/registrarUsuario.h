// registrarUsuario.h

#ifndef REGISTRAR_USUARIO_H
#define REGISTRAR_USUARIO_H

#include <iostream>
#include <vector>
#include "estructuras.h"  // Asumiendo que las estructuras están en este archivo

using namespace std;

// Función para registrar un nuevo usuario.
// Esta función permite a administradores y usuarios registrarse en el sistema.
// Los usuarios deben proporcionar un nombre de usuario y una contraseña.
// Los administradores pueden registrar a otros usuarios y tienen acceso a más funcionalidades.
void registrarUsuario(vector<Usuario>& usuarios, bool esAdministrador) {
    string nombreUsuario;
    string contrasena;

    cout << "Ingrese un nombre de usuario: ";
    cin >> nombreUsuario;

    // Validar si el nombre de usuario ya existe en la lista de usuarios.
    for (const Usuario& usuario : usuarios) {
        if (usuario.nombreUsuario == nombreUsuario) {
            cout << "El nombre de usuario ya está en uso. Por favor, elija otro nombre.\n";
            return;
        }
    }

    cout << "Ingrese una contraseña: ";
    cin >> contrasena;

    Usuario nuevoUsuario;
    nuevoUsuario.nombreUsuario = nombreUsuario;
    nuevoUsuario.contrasena = contrasena;

    if (esAdministrador) {
        // Si es un administrador, puede registrar usuarios y acceder a más funcionalidades.
        nuevoUsuario.esAdministrador = true;
        cout << "Nuevo usuario registrado como administrador.\n";
    } else {
        // Si no es un administrador, es un usuario regular.
        nuevoUsuario.esAdministrador = false;
        cout << "Nuevo usuario registrado como usuario regular.\n";
    }

    usuarios.push_back(nuevoUsuario);
    cout << "Registro exitoso.\n";
}

#endif // REGISTRAR_USUARIO_H
