#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <string>

void MostrarMenu() {
    cout << "\n--- Menú ---\n";
    cout << "1. Agregar Cliente\n";
    cout << "2. Mostrar Clientes\n";
    cout << "3. Buscar Cliente por RFC\n";
    cout << "4. Eliminar Cliente por RFC\n";
    cout << "5. Salir\n";
    cout << "Ingrese su opción: ";
}
