#ifndef MIPROYECTOMP_ADMINISTRADOR_H
#define MIPROYECTOMP_ADMINISTRADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_administrador();
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

void menu_administrador();
void alta_alumno();
void baja_alumno();
void modificar_alumno();
void opcion_alumnos();
void opcion_horarios();
void listar_alumnos();
void listar_materias_de_alumno(int id_alumno);
void modificar_matricula(int id_alumno);
void eliminar_matricula(int id_alumno);
void crear_matricula(int id_alumno);
void anadir_horas(int id_prof);
void eliminar_horas(int id_prof);
void modificar_horarios(int id_prof);
void listar_horarios(int id_prof);

#endif //MIPROYECTOMP_ADMINISTRADOR_H
