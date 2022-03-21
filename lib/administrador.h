//
// Created by aleja on 09/03/2022.
//

#ifndef MP2022_ADMINISTRADOR_H
#define MP2022_ADMINISTRADOR_H
#include "core.h"
#include <assert.h>

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
	printf("Introduce el ID del usuario a dar de baja: \n");
	scanf("%s", usuario.id);
	
	for(int i = 0; i < configuration.usuarios_counter; ++i){
		if(strcmp(usuario[i].id,usuario))
	}
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
	break;
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

#endif //MP2022_ADMINISTRADOR_H