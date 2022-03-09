#include <stdio.h>
#include <stdlib.h>
/*#include "core.h"*/

void perfil_profesor_menu_alum();
void perfil_profesor_listados();
void perfil_profesor_menu();



void perfil_profesor_listados(){

  printf("Listado de grupos y materias\n");
  printf("----------------------\n");
}


void perfil_profesor_menu(){
  int op;

   printf ("Menu: \n");
   printf("----------------------\n");
   printf("1.Lista de alumnos\n");
   printf("2.Cambiar de grupo\n");
   printf("----------------------\n");
   scanf("%i",&op);
   fflush(stdin);
   system("cls");
   switch (op)
   {
   case 1: perfil_profesor_menu_alum(); break;
   case 2: break;

   default: exit(-1); break;
   }

}

void perfil_profesor_menu_alum(){
  int op_alum;
   printf ("Menu: Lista de alumnos\n");
   printf("----------------------------\n");
   printf("1.Ficha del alumno\n");
   printf("2.Calificaciones del alumno\n");
   printf("3.Volver\n");
   printf("----------------------------\n");

   scanf("%i",&op_alum);
   fflush(stdin);
   switch (op_alum)
   {
   case 1: break;
   case 2: break;
   case 3: break;

   default: exit(-1); break;
   }

}


