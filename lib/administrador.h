//
// Created by aleja on 09/03/2022.
//

#ifndef MP2022_ADMINISTRADOR_H
#define MP2022_ADMINISTRADOR_H
#include "core.h"
#include <assert.h>

void dar_alta_usuario(){
	ALUMNOS = fopen("a","data/alumnos.txt");
	assert(ALUMNOS!=NULL);

	alumno alta_alumno;
	printf("Introduce el id\n");
	scanf("%s", alta_alumno.id);
	printf("Introduce el nombre\n");
	scanf("%s", alta_alumno.nombre);
	printf("Introduce la direccion")
	scanf("%s", alta_alumno.direc);
	printf("Introduce ")
}

void dar_baja_usuario(){
	
}

void modificar_usuario(){
	
}

void listar_usuario(){

}

#endif //MP2022_ADMINISTRADOR_H