//FUNCIONES USUARIOS Y MATERIAS DEL MODULO ADMINISTRADOR

#include "lib/core.h"
#include "lib/administrador_usuariosmaterias.h"

//Cabecera: void menu_administrador()
//Precondición: el usuario ha seleccionado el perfil administrador.
//Postcondición: se muestran las opciones del menu administrador: usuarios, alumnos, materias, horarios.
void menu_administrador(){
    int opc;
    do{
        printf(" ____________________________________________________________\n |Menu:Administrador                                        |\n |----------------------------------------------------------|\n |                  1.Usuario                               |\n |                  2.Alumnos                               |\n |                  3.Materias                              |\n |                  4.Horarios                              |\n |__________________________________________________________|\n");
        scanf("%i",&opc);
    }while(opc<1 || opc>4);//fin_do_While
    switch(opc){
        case 1: system("cls"); opcion_usuarios();break;
        case 2: system("cls"); opcion_alumnos();break;
        case 3: system("cls"); opcion_materias();break;
        case 4: system("cls"); opcion_horarios();break;
    }//fin_switch
}//fin_void

//Cabecera: void opcion_usuarios()
//Precondición: el administrador ha seleccionado la opcion 1: usuarios.
//Postcondición: permite acceder a las distintas funcionalidades del menu usuario: dar de alta, dar de baja, modificar y listar usuarios.
void opcion_usuarios(){
	int opc, salida = 0;
	do{
		printf("Seleccione que opcion desea\n\t1.Dar de alta usuario\n\t2.Dar de baja usuario\n\t3.Modificar usuario\n\t4.Listar usuarios\n\t5.Salir\n");
		scanf("%d", &opc)
		switch(opc){
			case 1: alta_usuario(); break;
            	case 2: baja_usuario(); break;
            	case 3: modificar_usuario(); break;
            	case 4: listar_usuarios(); break;
            	case 5: salida=1; break;
        	}//fin_switch
    }while(opc<1 || opc>5 && salida==0);//fin_do_while
}//fin_void

//Cabecera: void opcion_materias()
//Precondición: el administrador ha seleccionado la opcion 3: materias.
//Postcondición: permite acceder a las distintas funcionalidades del menú materias: dar de alta, dar de baja, modificar y listar materias.
void opcion_materias(){
	int opc, salida = 0;
	do{
		printf("Seleccione que opcion desea\n\t1.Dar de alta materia\n\t2.Dar de baja materia\n\t3.Modificar materia\n\t4.Listar materias\n\t5.Salir\n");
		scanf("%d", &opc)
		switch(opc){
			case 1: alta_materia(); break;
            	case 2: baja_materia(); break;
            	case 3: modificar_materia(); break;
            	case 4: listar_materias(); break;
            	case 5: salida=1; break;
        	}//fin_switch
    }while(opc<1 || opc>5 && salida==0);//fin_do_while
}//fin_void

//Mini módulo Administrador - Usuarios

//Cabecera: void baja_usuario()
//Precondición: ninguna.
//Postcondición: elimina al usuario cuyo id ha sido seleccionado satisfactoriamente.
void baja_usuario(){
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
        }//fin_if
    }//fin_for

    if(counter == 0) printf("\nEl identificador introducido es incorrecto o no existe\n");
    core_usuarios_update;
}//fin_void

//Cabecera: void modificar_usuario()
//Precondición: ninguna.
//Postcondición: modifica el campo seleccionado por el administrador para el usuario cuya id sea correspondiente satisfactoriamente.
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
			}//fin_switch
			core_usuarios_update();
		}//fin_if
	}//fin_for
}//fin_void

//Cabecera: void listar_usuarios()
//Precondición: ninguna.
//Postcondición: muestra por pantalla la lista de usuarios disponibles.
void listar_usuarios(){
	assert(USUARIOS_FILE!=NULL);
	for (int i = 0; i < configuration.usuarios_counter; ++i){
        printf("ID: %s\n", usuario[i].id);
        printf("Nombre Completo del Usuario: %s\n", usuario[i].nombre);
        printf("Perfil: %s\n", usuario[i].perfil);
	   printf("Name Tag: %s\n", usuario[i].name_tag);
	   printf("Password: %s\n", usuario[i].password);
	}//fin_for
}//fin_void

//Mini módulo Administrador - Materias

//Cabecera: void alta_materia()
//Precondición: fichero "materias.txt" existente.
//Postcondición: guarda en el fichero "materias.txt" una nueva materia satisfactoriamente.
void alta_materia(){
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
	core_materias_update();
}//fin_void

//Cabecera: void baja_materia()
//Precondición: ninguna.
//Postcondición: elimina la materia cuyo id ha sido seleccionado satisfactoriamente.
void baja_materia(){
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

//Cabecera: void modificar_materia()
//Precondición: ninguna.
//Postcondición: modifica el campo seleccionado por el administrador para la materia cuya id sea correspondiente satisfactoriamente.
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

//Cabecera: void listar_materias()
//Precondición: ninguna.
//Postcondición: muestra por pantalla la lista de materias disponibles.
void listar_materias(){
	assert(MATERIAS_FILE!=NULL);
	for (int i = 0; i < configuration.materias_counter; ++i){
       printf("ID: %s\n", materia[i].id);
       printf("Nombre de la materia: %s\n", materia[i].nombre);
       printf("Abreviatura: %s\n", materia[i].abrev);
	}
}