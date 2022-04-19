#ifndef MIPROYECTOMP_ADMINISTRADOR_H
#define MIPROYECTOMP_ADMINISTRADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_administrador(int logged_user);
void opcion_usuarios();
void opcion_materias();
void alta_usuario();
void baja_usuario();
void modificar_usuario();
void listar_usuarios();
void alta_materia();
void baja_materia();
void modificar_materia();
void listar_materias();

void alta_alumno();
void baja_alumno();
void modificar_alumno();
void opcion_alumnos();
void opcion_horarios();
void listar_alumnos();
void listar_materias_de_alumno(char id_alumno[]);
void modificar_matricula(char id_alumno[]);
void eliminar_matricula(char id_alumno[]);
void crear_matricula(char id_alumno[]);
void anadir_horas(char id_prof[]);
void eliminar_horas(char id_prof[]);
void modificar_horarios(char id_prof[]);
void listar_horarios(char id_prof[]);
void espacios_desc(char aux[]);

#endif //MIPROYECTOMP_ADMINISTRADOR_H
