//
// Created by aleja on 09/03/2022.
//

#ifndef MP2022_ADMINISTRADOR_H
#define MP2022_ADMINISTRADOR_H
#include "core.h"
#include <assert.h>

//Mini módulo Administrador - Usuarios

void dar_alta_usuario(){
	USUARIOS_FILE = fopen("a","data/usuarios.txt");
	assert(USUARIOS_FILE!=NULL);

	usuario alta_usuario;
	printf("Introduce el id\n");
	scanf("%s", alta_usuario.id);
	printf("Introduce el nombre completo del usuario\n");
	scanf("%s", alta_usuario.nombre);
	printf("Introduce el perfil del usuario: administrador o profesor\n");
	scanf("%s", alta_usuario.perfil);
	printf("Introduce el nombre de usuario\n");
	scanf("%s", alta_usuario.name_tag);
	printf("Introduce la password\n");
	scanf("%s", alta_usuario.password);
	
	fprintf(ALUMNOS, "%s", alta_usuario.id);
	fprintf(ALUMNOS, "%c", "\n");
	fprintf(ALUMNOS, "%s", alta_usuario.nombre);
	fprintf(ALUMNOS, "%c", "\n");
	fprintf(ALUMNOS, "%s", alta_usuario.perfil);
	fprintf(ALUMNOS, "%c", "\n");
	fprintf(ALUMNOS, "%s", alta_usuario.name_tag);
	fprintf(ALUMNOS, "%c", "\n");
	fprintf(ALUMNOS, "%s", alta_usuario.password);
	fclose(ALUMNOS);
}

void dar_baja_usuario(){
    char idequal[3];
    int cont = 0;

    printf("Introduzca identificador del usuario que desea eliminar: \n");
    scanf("%s", &idequal);
    fflush(stdin);
    for (int i = 0; i<configuration.usuarios_counter; ++i){
        if(strcmp(idequal,usuario[i].id) == 0){
            cont++;
            strcpy(usuario[i].id, "");
		  strcpy(usuario[i].nombre, "");
		  strcpy(usuario[i].perfil, "");
		  strcpy(usuario[i].name_tag, "");
		  strcpy(usuario[i].password, "");
        }
    }
    if(counter == 0) printf("\nEl identificador introducido es incorrecto o no existe\n");
    core_usuarios_update;
}

void modificar_usuario(){
	printf("Introduce el ID del usuario a modificar: \n");
	scanf("%s", usuario.id);
	
	for(int i = 0; i < configuration.usuarios_counter; ++i){
		if(strcmp(usuario[i].id,usuario.id) == 0){
			printf("Selecciona que quieres cambiar: \n");
			printf("1)Id\t\n2)Nombre\t\n3)Perfil\t\n4)Name Tag\t\n5)Password");
				scanf("%d",&opcion);
			switch(opcion){
				case 1:
					printf("Introduce el Id\n");
					scanf("%s", usuario[i].id);
					break;
				case 2:
					printf("Introduce el nombre completo del usuario\n");
					scanf("%s", usuario[i].nombre);
					break;
				case 3:
					printf("Introduce el perfil\n");
					scanf("%s", usuario[i].perfil);
					break;
				case 4:
					printf("Introduce el nombre de usuario\n");
					scanf("%s", usuario[i].name_tag);
					break;
				case 5:
					printf("Introduce la password\n");
					scanf("%s", usuario[i].password);
					break;
			}
			core_usuarios_update();
		}
	}
}

void listar_usuario(){
	assert(USUARIOS_FILE!=NULL);
	for (int i = 0; i < configuration.usuarios_counter; ++i){
        printf("ID: %s\n", usuario[i].id);
        printf("Nombre Completo del Usuario: %s\n", usuario[i].nombre);
        printf("Perfil: %s\n", usuario[i].perfil);
	  printf("Name Tag: %s\n", usuario[i].name_tag);
	  printf("Password: %s\n", usuario[i].password);
	}
}

//Mini módulo Administrador - Materias

void dar_alta_materia(){
	MATERIAS_FILE = fopen("a","data/materias.txt");
	assert(MATERIAS_FILE!=NULL);

	materia alta_materia;
	printf("Introduce el id\n");
	scanf("%s", alta_materia.id);
	printf("Introduce el nombre de la materia\n");
	scanf("%s", alta_materia.nombre);
	printf("Introduce la abreviatura de la materia\n");
	scanf("%s", alta_materia.abrev);
	
	fprintf(MATERIAS, "%s", alta_materia.id);
	fprintf(MATERIAS, "%c", "\n");
	fprintf(MATERIAS, "%s", alta_materia.nombre);
	fprintf(MATERIAS, "%c", "\n");
	fprintf(MATERIAS, "%s", alta_materia.abrev);
	fprintf(MATERIAS, "%c", "\n");
	fclose(MATERIAS);
}

void dar_baja_materia(){
    char idequal[4];
    int cont = 0;

    printf("Introduzca el identificador de la materia que desea eliminar: \n);
    scanf("%s", &idequal);
    fflush(stdin);
    for (int i = 0; i<configuration.materias_counter; ++i){
        if(strcmp(idequal, materia[i].id) == 0){
            cont++;
            strcpy(materia[i].id, "");
		  strcpy(materia[i].nombre, "");
		  strcpy(materia[i].abrev, "");
        }
    }
    if(counter == 0) printf("\nEl identificador introducido es incorrecto o no existe\n");
    core_materias_update;
}

void modificar_materia(){
	printf("Introduce el ID de la materia a modificar: \n");
	scanf("%s", materia.id);
	
	for(int i = 0; i < configuration.materias_counter; ++i){
		if(strcmp(materia[i].id,materia.id) == 0){
			printf("Selecciona que quieres cambiar: \n");
			printf("1)Id\t\n2)Nombre\t\n3)Abreviatura");
				scanf("%d",&opcion);
			switch(opcion){
				case 1:
					printf("Introduce el Id\n");
					scanf("%s", materia[i].id);
					break;
				case 2:
					printf("Introduce el nombre de la materia\n");
					scanf("%s", materia[i].nombre);
					break;
				case 3:
					printf("Introduce la abreviatura\n");
					scanf("%s", materia[i].abrev);
					break;
			}
			core_materias_update();
		}
	}
}

void listar_materias(){
	assert(MATERIAS_FILE!=NULL);
	for (int i = 0; i < configuration.materias_counter; ++i){
       printf("ID: %s\n", materia[i].id);
       printf("Nombre de la materia: %s\n", materia[i].nombre);
       printf("Abreviatura: %s\n", materia[i].abrev);
	}
}

#endif //MP2022_ADMINISTRADOR_H