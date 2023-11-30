#ifndef ListaMain_H
#define ListaMain_H

#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string nombre;
    string correo;
    string telefono;
    string rfc;

public:
    Cliente(const string& n, const string& c, const string& t, const string& r);

    void MostrarCliente() {
        cout << "\n------------------------------------------------------";
        cout << "\n\tNombre: " << nombre;
        cout << "\n\tCorreo: " << correo;
        cout << "\n\tTeléfono: " << telefono;
        cout << "\n\tRFC: " << rfc;
        cout << "\n------------------------------------------------------";
    }

    const string& ObtenerRFC() const {
        return rfc;
    }
};

class ListaClientes {
private:
    Cliente** clientes;
    int cantidadClientes;

public:

   ListaClientes() : clientes(nullptr), cantidadClientes(0) {}

    ~ListaClientes() {
        LimpiarClientes();
    }

    void AgregarCliente(const string& nombre, const string& correo, const string& telefono, const string& rfc) {
        Cliente* nuevoCliente = new Cliente(nombre, correo, telefono, rfc);

        // Redimensionar el arreglo dinámicamente
        Cliente** nuevosClientes = new Cliente*[cantidadClientes + 1];
        for (int i = 0; i < cantidadClientes; ++i) {
            nuevosClientes[i] = clientes[i];
        }

        nuevosClientes[cantidadClientes] = nuevoCliente;

        delete[] clientes;
        clientes = nuevosClientes;

        ++cantidadClientes;

        cout << "\nCliente agregado correctamente.\n";
    }

    void MostrarClientes() {
        if (cantidadClientes == 0) {
            cout << "\n\tLa lista de clientes está vacía.\n";
        } else {
            cout << "\n\tLista de Clientes:\n";
            for (int i = 0; i < cantidadClientes; ++i) {
                clientes[i]->MostrarCliente();
                cout << endl;
            }
        }
    }

    bool BuscarClientePorRFC(const string& rfc) {
        for (int i = 0; i < cantidadClientes; ++i) {
            if (clientes[i]->ObtenerRFC() == rfc) {
                cout << "\nCliente encontrado:\n";
                clientes[i]->MostrarCliente();
                return true;
            }
        }
        cout << "\nCliente con RFC '" << rfc << "' no encontrado.\n";
        return false;
    }

    void EliminarClientePorRFC(const string& rfc) {
        for (int i = 0; i < cantidadClientes; ++i) {
            if (clientes[i]->ObtenerRFC() == rfc) {
                delete clientes[i];

                // Mover los clientes restantes hacia arriba en el arreglo
                for (int j = i; j < cantidadClientes - 1; ++j) {
                    clientes[j] = clientes[j + 1];
                }

                --cantidadClientes;

                cout << "\nCliente con RFC '" << rfc << "' eliminado correctamente.\n";
                return;
            }
        }
        cout << "\nCliente con RFC '" << rfc << "' no encontrado.\n";
    }

    void LimpiarClientes() {
        for (int i = 0; i < cantidadClientes; ++i) {
            delete clientes[i];
        }
        delete[] clientes;
    }

//HABITACIONES

};
class Habitacion {
private:
    int numero;
    bool disponible;
    string ocupante;

public:
    Habitacion(int num) : numero(num), disponible(true), ocupante("") {}

    void MostrarHabitacion() {
        cout << "\n------------------------------------------------------";
        cout << "\n\tNúmero de Habitación: " << numero;
        cout << "\n\tEstado: " << (disponible ? "Disponible" : "No Disponible");
        if (!disponible) {
            cout << "\n\tOcupante: " << ocupante;
        }
        cout << "\n------------------------------------------------------";
    }

    void CambiarDisponibilidad() {
        disponible = !disponible;
        if (!disponible) {
            cout << "\nIngrese el nombre del ocupante: ";
            cin.ignore(); // Limpiar el buffer
            getline(cin, ocupante);
        } else {
            ocupante = ""; // Limpiar el nombre del ocupante si la habitación está disponible
        }
    }

    bool EstaDisponible() const {
        return disponible;
    }
};

class ListaHabitaciones {
private:
    Habitacion* habitaciones[10];

public:
    ListaHabitaciones() {
        for (int i = 0; i < 10; ++i) {
            habitaciones[i] = new Habitacion(i + 1);
        }
    }

    ~ListaHabitaciones() {
        for (int i = 0; i < 10; ++i) {
            delete habitaciones[i];
        }
    }

    void MostrarLista() {
        cout << "\n\tLista de Habitaciones:\n";
        for (int i = 0; i < 10; ++i) {
            habitaciones[i]->MostrarHabitacion();
            cout << endl;
        }
    }

    void CambiarEstadoHabitacion() {
        int numHabitacion;
        cout << "\nIngrese el número de la habitación que desea cambiar (1-10): ";
        cin >> numHabitacion;

        if (numHabitacion >= 1 && numHabitacion <= 10) {
            habitaciones[numHabitacion - 1]->CambiarDisponibilidad();
            cout << "\nEstado de la habitación cambiado exitosamente.\n";
        } else {
            cout << "\nNúmero de habitación inválido.\n";
        }
    }
};


#endif
