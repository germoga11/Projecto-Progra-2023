#include <iostream>
#include <string>
#include "ListaMain.h"


using namespace std;

//clases
    class Empleado {
        friend class Gerentes;
        friend class Administradores;
        friend class Servicio;
        
        protected:
            string nombre;
            string direccion;
            string telfono;
            string rfc;
            string puesto;
            int id;//codigo de empleado

        public:
            int salario;


    };

    class Gerentes{
        // salario 25000
    };

    class Administradores{
        //salario 8000 + 5% de cada huesped

    };
    class Servicio{
        
        //salario 6000

    };

    class Cliente {
        string nombre;
        string direccion;
        string telfono;
        string rfc;
        string correo;

    };

    class Habitacion {
        protected:
            int cde;// codigo del empleado que reservo la habitacion
            int numero_de_habitacion;
            float precio;
            string estado;
        public:

    };

//Funciones



// MENU 

int main(){
int eleccion;
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
            cin >> eleccion;

            
            switch (eleccion) {
                case 1:
                    cout << "-Empleados-\n"<<"\n";
                    cout << "1. Ingresar un nuevo registro\n";
                    cout << "2. Consultar uno o varios registros \n";
                    cout << "3. Eliminar un registro\n";
                    cout << "4. Renta de habitacion\n";
                    cin >> "eleccion";
                    system("cls");
                        switch (eleccion) {
                            case 1:
                        
                            break;

                            case 2:

                            break;
                            case 3; 

                            break;
                case 2:
                    cout << "-Clientes-\n" << "\n";
                
                    cout << "1. Ingresar un nuevo registro\n";
                    cout << "2. Consultar uno o varios registros \n";
                    cout << "3. Eliminar un registro\n";
                    cout << "4. Renta de habitacion\n";
                    break;
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
