#include <iostream>
#include <string>
#include "ListaMain.h"


using namespace std;

int main(){
int opcion;
    do {
            // Menu Principal
            cout << "Menu:\n";
            cout << "1. Empleados \n";
            cout << "2. Clientes \n";
            cout << "3. Habitacion\n";
            cout << "4. Renta de habitacion\n";
            cout << "5. Reportes\n";
            cout << "6. Salir\n";

           
            cout << "Elija una opcion: ";
            cin >> opcion;

            
            switch (opcion) {
                case 1:
                    cout << "-Empleados-\n"<<"\n";
                    cout << "1. Ingresar un nuevo registro\n";
                    cout << "2. Consultar uno o varios registros \n";
                    cout << "3. Eliminar un registro\n";
                    cout << "4. Renta de habitacion\n";
                    cin >> "eleccion";
                    system("cls");
                                        switch (opcion) {
                                             case 1:
                                        
                                            break;
                
                                            case 2:
                
                                            break;
                                            case 3; 
                
                                            break;
                                        }
                case 2:
                    MostrarMenu();
                    cin >> opcion;
                switch (opcion) {
                            case 1:
                                cout << "\nIngrese el nombre del cliente: ";
                                cin.ignore();
                                getline(cin, nombre);
                
                                cout << "Ingrese el correo del cliente: ";
                                getline(cin, correo);
                
                                cout << "Ingrese el teléfono del cliente: ";
                                getline(cin, telefono);
                
                                cout << "Ingrese el RFC del cliente: ";
                                getline(cin, rfc);
                
                                lista.AgregarCliente(nombre, correo, telefono, rfc);
                                break;
                
                            case 2:
                                lista.MostrarClientes();
                                break;
                
                            case 3:
                                cout << "\nIngrese el RFC del cliente a buscar: ";
                                cin.ignore();
                                getline(cin, rfc);
                                lista.BuscarClientePorRFC(rfc);
                                break;
                
                            case 4:
                                cout << "\nIngrese el RFC del cliente a eliminar: ";
                                cin.ignore();
                                getline(cin, rfc);
                                lista.EliminarClientePorRFC(rfc);
                                break;
                                    break;
                                }
                            
                case 3:
                    cout << "-Habitacion-\n";
                
                    cout << "Porfavor ingresa tu numero de cliente:\n";
                    
                    //funcion que cheque si el numero de cliente es valido
                        //info de la habitacion
                
                    break;
                    
                case 4:
                    cout << "-Renta de habitacion-\n";
                
                    cout << "Porfavor ingresa tu numero de cliente:\n";
                
                
                    break;
                case 5:
                    cout << "-Reportes-\n";
                    
                
                    cout << "1. Lista de Clientes\n";
                    cout << "2. Lista de habitaciones totales\n";
                    cout << "3. Reporte de Habitaciones disponibles\n";
                    cout << "4. Reporte de Habitaciones NO disponibles\n";
                    cout << "5. Lista de Empleados\n";
                    cout << "6. Lista de empleados acuerdo a tipos\n";
                    
                    
                    
                    break;
                case 6:
                    cout << "Saliendo del Programa . . .\n";
                    break;
                default:
                    cout << "Opcion invalida \n";
            }

        } while (eleccion != 6);
}
