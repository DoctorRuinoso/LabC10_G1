#ifndef profesor_H
#define profesor_H



//Cabecera:void perfil_profesor_menu_general()
//Precondicion:Ninguna
//Postcondicion:Mostrar el menú general
void perfil_profesor_menu_general();


//Cabecera:int perfil_profesor_listados()
//Precondicion:Ninguna
//Postcondicion:Mostrar el listado de grupo y materias y seleccionar el correspondiente.
int perfil_profesor_listados();


//Cabecera:void perfil_profesor_menu_profesor()
//Precondicion:El profesor ha accedido al grupo seleccionado
//Postcondicion:El profesor ve la lista de alumnos o cambia el grupo correspondiente.

void perfil_profesor_menu_profesor();

//Cabecera:void perfil_profesor_menu_alum()
//Precondicion:El profesor  ha seleccionado la lista de alumnos
//Postcondicion:El profesor lee la ficha de los alumnos y las calificaciones
int perfil_profesor_menu_alum();

//Cabecera:vperfil_profesor_ficha_alumno();
//Precondicion:recibe el id alumno y muestra sus datos
//Postcondicion:El profesor modifica los datos del alumno.
void perfil_profesor_ficha_alumno();

//Cabecera:perfil_profesor_calif_alumno()
//Precondicion:recibe el id alumno y se muestra sus calificaciones
//Postcondicion:El profesor modifica los datos del alumno.
void perfil_profesor_calif_alumno();

#endif