#ifndef profesor_H
#define profesor_H

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


//Cabecera:void perfil_profesor_menu_general()
//Precondicion:Ninguna
//Postcondicion:Mostrar el menú general
int perfil_profesor_menu_general(unsigned logged_user);


//Cabecera:int perfil_profesor_listados()
//Precondicion:Ninguna
//Postcondicion:Mostrar el listado de grupo y materias y seleccionar el correspondiente.
int perfil_profesor_listados(unsigned logged_user);

//Cabecera:void perfil_profesor_menu_profesor()
//Precondicion:El profesor ha accedido al grupo seleccionado
//Postcondicion:El profesor ve la lista de alumnos o cambia el grupo correspondiente.

void perfil_profesor_menu_profesor(unsigned logged_user);

//Cabecera:void perfil_profesor_menu_alum()
//Precondicion:El profesor  ha seleccionado la lista de alumnos
//Postcondicion:El profesor lee la ficha de los alumnos y las calificaciones
int perfil_profesor_menu_alum(unsigned logged_user);

//Cabecera:vperfil_profesor_ficha_alumno();
//Precondicion:recibe el id alumno y muestra sus datos
//Postcondicion:El profesor modifica los datos del alumno.
void perfil_profesor_ficha_alumno(unsigned logged_user);

//Cabecera:perfil_profesor_calif_alumno()
//Precondicion:recibe el id alumno y se muestra sus calificaciones
//Postcondicion:El profesor modifica los datos del alumno.
void perfil_profesor_calif_alumno(unsigned logged_user);


//Cabecera:void perfil_profesor_modificar_alumno()
//Precondicion:recibe el id alumno 
//Postcondicion:El profesor modifica los datos del alumno.
void perfil_profesor_modificar_alumno(unsigned logged_user);

//Cabecera:void perfil_profesor_modificar_calif()
//Precondicion:recibe el id alumno 
//Postcondicion:El profesor modifica los datos del alumno.
void perfil_profesor_modificar_calif(unsigned logged_user);

//Cabecera:void perfil_profesor_annadir_calif();
//Precondicion:recibe el id alumno 
//Postcondicion:El profesor modifica los datos del alumno.
void perfil_profesor_annadir_calif(unsigned logged_user);

//Cabecera:void perfil_profesor_borrar_calif()
//Precondicion:recibe el id alumno 
//Postcondicion:El profesor modifica los datos del alumno.
void perfil_profesor_borrar_calif(unsigned logged_user);



#endif