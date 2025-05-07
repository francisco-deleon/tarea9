#pragma once
#include "ConexionBD.h"
#include "Persona.h"
#include <iostream>
#include <mysql.h>
#include <string>

using namespace std;

class Estudiante : Persona {
	// atributos
private:
	string codigo;
	int id_estudiante = 0;

public:
	// constructor vacio
	Estudiante() {}

	// constructor heredado
	Estudiante(string nom, string ape, string dir, int tel, string fnac, int id_ts, string cod, int id_est) : Persona(nom, ape, dir, tel, fnac, id_ts) {
		codigo = cod;
		id_estudiante = id_est;

	}

	// metodos GET y SET
	// SET (modificar un atributo)
	void setId_Estudiante(int e) {
		id_estudiante = e;
	}

	void setCodigo(string c) {
		codigo = c;
	}

	void setNombres(string n) {
		nombres = n;
	}

	void setApellidos(string a) {
		apellidos = a;
	}

	void setDireccion(string d) {
		direccion = d;
	}

	void setTelefono(int t) {
		telefono = t;
	}

	void setFecha_Nacimiento(string f) {
		fecha_nacimiento = f;
	}

	void setId_Tipo_Sangre(int ts) {
		id_tipo_sangre = ts;
	}

	// GET (obtener un atributo)
	int getId_Estudiante() {
		return id_estudiante;
	}

	string getCodigo() {
		return codigo;
	}

	string getNombres() {
		return nombres;
	}

	string getApellidos() {
		return apellidos;
	}

	string getDireccion() {
		return direccion;
	}

	int getTelefono() {
		return telefono;
	}

	string getFecha_Nacimiento() {
		return fecha_nacimiento;
	}

	int getId_Tipo_Sangre() {
		return id_tipo_sangre;
	}

	// metodos
	void crear() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string campos = "(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre)";
			string valores = " VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + to_string(telefono) + ",'" + fecha_nacimiento + "'," + to_string(id_tipo_sangre) + ");";
			string consulta = "INSERT INTO estudiantes" + campos + valores;
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConector(), c);

			if (!q_estado) {
				cout << "Ingreso de datos exitoso.. \n" << endl;
			}
			else {
				cout << "xxx Consulta Fallida xxx" << endl;
			}
		}
		else {
			cout << "xxx Conexion Fallida xxx" << endl;
		}

		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConector()) {
			cout << "____________ Datos del Estudiante ____________" << endl;
			string campos = "SELECT e.id_estudiante as id, e.codigo, e.nombres, e.apellidos, e.direccion, e.telefono, e.fecha_nacimiento, ts.sangre";
			string join = "INNER JOIN tipos_sangre AS ts ON e.id_tipo_sangre = ts.id_tipo_sangre;";
			string consulta = campos + " FROM estudiantes as e " + join;
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConector(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConector());

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << endl;
				}

				cout << endl;
			}
			else {
				cout << "xxx Consulta Fallida xxx" << endl;
			}
		}
		else {
			cout << "xxx Fallo la Conexion xxx" << endl;
		}

		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string valores = "codigo ='" + codigo + "', nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = " + to_string(telefono) + ", fecha_nacimiento = '" + fecha_nacimiento + "', id_tipo_sangre = " + to_string(id_tipo_sangre);
			string condicion = " WHERE id_estudiante = " + to_string(id_estudiante) + ";";
			string consulta = "UPDATE estudiantes SET " + valores + condicion;
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConector(), c);

			if (!q_estado) {
				cout << "Modificacion de datos exitosa.. \n" << endl;
			}
			else {
				cout << "xxx Modificacion Fallida xxx" << endl;
			}
		}
		else {
			cout << "xxx Conexion Fallida xxx" << endl;
		}

		cn.cerrar_conexion();
	}

	void borrar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string condicion = " WHERE id_estudiante = " + to_string(id_estudiante) + ";";
			string consulta = "DELETE FROM estudiantes" + condicion;
			const char* c = consulta.c_str();

			q_estado = mysql_query(cn.getConector(), c);

			if (!q_estado) {
				cout << "Eliminacion de datos exitosa.. \n" << endl;
			}
			else {
				cout << "xxx Eliminacion Fallida xxx" << endl;
			}
		}
		else {
			cout << "xxx Conexion Fallida xxx" << endl;
		}

		cn.cerrar_conexion();
	}
};

