#include <iostream>
#include "Estudiante.h"

using namespace std;

int main() {
    string codigo, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono = 0, id_tipo_sangre = 0, id_estudiante = 0;

    // Creacion
    cout << "Ingrese Codigo: ";
    cin >> codigo;
    cin.ignore();
    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento: ";
    getline(cin, fecha_nacimiento);
    cout << "Ingrese Tipo de Sangre: ";
    cin >> id_tipo_sangre;
    cout << endl;

    Estudiante e = Estudiante(nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre, codigo, id_estudiante);
    e.crear();
    e.leer();

    // Actualizacion
    cout << "Ingrese el ID a Modificar: ";
    cin >> id_estudiante;
    cout << "Ingrese Codigo: ";
    cin >> codigo;
    cin.ignore();
    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento: ";
    getline(cin, fecha_nacimiento);
    cout << "Ingrese Tipo de Sangre: ";
    cin >> id_tipo_sangre;
    cout << endl;

    e.setId_Estudiante(id_estudiante);
    e.setCodigo(codigo);
    e.setNombres(nombres);
    e.setApellidos(apellidos);
    e.setDireccion(direccion);
    e.setTelefono(telefono);
    e.setFecha_Nacimiento(fecha_nacimiento);
    e.setId_Tipo_Sangre(id_tipo_sangre);
    
    e.actualizar();
    e.leer();

    // Eliminacion
    cout << "Ingrese el ID a Eliminar: ";
    cin >> id_estudiante;
    cout << endl;

    e.setId_Estudiante(id_estudiante);
    e.borrar();
    e.leer();
}
