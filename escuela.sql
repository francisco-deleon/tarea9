/*
  Script SQL de la Tarea 9 C++ y MySQL
  Programación I

  Universidad Mariano Gálvez de Guatemala
  Facultad de Ingeniería en Sistemas

  Autor:
  Francisco Antonio De León Natareno
*/

-- Crear nuevo usuario 'usr_escuela' contraseña 'Escuela@123-2025'
CREATE USER 'usr_escuela'@'localhost' IDENTIFIED BY 'Escuela@123-2025';

-- Asignar los permisos necesarios al nuevo usuario 'usr_escuela' en la base de datos 'db_escuela'
GRANT SELECT, INSERT, UPDATE, DELETE, EXECUTE, SHOW VIEW ON db_escuela.* TO 'usr_escuela'@'localhost';

-- Recargar la tabla de permisos
FLUSH PRIVILEGES;

-- Crear base de datos 'db_escuela'
CREATE DATABASE IF NOT EXISTS db_escuela;

-- Seleccionar la BD 'db_escuela'
USE db_escuela;

-- Crear tabla 'tipos_sangre'
CREATE TABLE tipos_sangre(
 id_tipo_sangre SMALLINT AUTO_INCREMENT PRIMARY KEY,
 sangre VARCHAR(5) NULL
);

-- Crear tabla 'estudiantes'
CREATE TABLE estudiantes(
 id_estudiante INT AUTO_INCREMENT PRIMARY KEY,
 codigo VARCHAR(4),
 nombres VARCHAR(60),
 apellidos VARCHAR(60),
 direccion VARCHAR(100),
 telefono INT,
 fecha_nacimiento DATE,
 id_tipo_sangre SMALLINT,
 CONSTRAINT FK_id_tipo_sangre_estudiantes_tipos_sangre FOREIGN KEY (id_tipo_sangre) REFERENCES tipos_sangre(id_tipo_sangre) ON UPDATE CASCADE
);

-- Insertar registros de prueba en la tabla 'tipos_sangre'
INSERT INTO tipos_sangre(sangre) VALUES
  ('O-'),
  ('A+');
  
-- Insertar registros de prueba en la tabla 'estudiantes'
INSERT INTO estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre) VALUES
  ('E001', 'Jose Luis', 'Peres Lopez', 'Guatemala', 5555, '1990-01-22', 1),
  ('E002', 'Maria Fernanda', 'Ortiz Sosa', 'Ciudad', 222, '1995-01-01', 2);
  
SELECT e.id_estudiante as id, e.codigo, e.nombres, e.apellidos, e.direccion, e.telefono, e.fecha_nacimiento, ts.sangre FROM estudiantes as e INNER JOIN tipos_sangre AS ts ON e.id_tipo_sangre = ts.id_tipo_sangre;