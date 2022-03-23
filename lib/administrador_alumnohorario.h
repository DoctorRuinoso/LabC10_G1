#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_



#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void menu_administrador();
void alta_alumno();
void baja_alumno();
void modificar_alumno();
void opcion_alumnos();
void opcion_horarios();
void listar_alumnos();
void listar_materias(int id_alumno);
void modificar_matricula(int id_alumno);
void eliminar_matricula(int id_alumno);
void crear_matricula(int id_alumno);
void anadir_horas(int id_prof);
void eliminar_horas(int id_prof);
void modificar_horarios(int id_prof);
void listar_horarios(int id_prof);

#endif
