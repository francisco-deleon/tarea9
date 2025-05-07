#pragma once
#include <mysql.h>
#include <iostream>

using namespace std;

class ConexionBD {
private:
	MYSQL* conector; // controla el estado de la conexion a la BD
	static constexpr const char* SERVIDOR = "localhost"; // nombre de servidor (host)
	static constexpr const char* USUARIO = "usr_escuela"; // nombre de usuario
	static constexpr const char* CLAVE = "Escuela@123-2025"; // contraseña
	static constexpr const char* BD = "db_escuela"; // base de datos
	static const int PUERTO = 3307; // puerto de conexión

public:
	void abrir_conexion() {
		conector = mysql_init(0);
		conector = mysql_real_connect(conector, SERVIDOR, USUARIO, CLAVE, BD, PUERTO, NULL, 0);
	}

	MYSQL* getConector() {
		return conector;
	}

	void cerrar_conexion() {
		mysql_close(conector);
	}

};
