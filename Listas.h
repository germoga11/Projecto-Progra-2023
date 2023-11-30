#ifndef ListaMain_H
#define ListaMain_H

#include <iostream>
#include <string>

class Cliente {
private:
    std::string nombre;
    std::string correo;
    std::string telefono;
    std::string rfc;

public:
    Cliente(const std::string& n, const std::string& c, const std::string& t, const std::string& r);

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

   ListaClientes() : clientes(NULL), cantidadClientes(0) {}

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
};

#endif 


