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
void listar_materias(int id);
void modificar_matricula(int id);
void eliminar_matricula(int id);
void crear_matricula(int id);
void anadir_horas();
void eliminar_horas();
void modificar_horarios();
void listar_horarios();

#endif
