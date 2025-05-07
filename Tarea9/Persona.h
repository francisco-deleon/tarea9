#pragma once
#include <iostream>

using namespace std;

class Persona {
	// atributos
protected:
	string nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tipo_sangre = 0;

	// constructor vacio
	Persona() {}

	Persona(string nom, string ape, string dir, int tel, string fnac, int id_ts) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fnac;
		id_tipo_sangre = id_ts;
	}
};
