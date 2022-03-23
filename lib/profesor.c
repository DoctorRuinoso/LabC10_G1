#include <stdio.h>
#include <stdlib.h>
#include "core.h"

void perfil_profesor_menu_alum();
void perfil_profesor_listados();
void perfil_profesor_menu_profesor();
void perfil_profesor_menu_general();


void perfil_profesor_menu_general(){

 perfil_profesor_listados();
 system("cls");
 perfil_profesor_menu_profesor();

}




void perfil_profesor_listados(){

  int op_listado;

  printf("Listado de grupos y materias\n");
  printf("----------------------------\n");
  system("pause");
  

  core_horarios_recovery();

  for (int i = 0; i < configuration->horarios_counter; ++i) {

      if (horarios[i].id_profesor==usuarios[].id){


     for(int j=0; j<configuration->matriculas_counter){
      
      if (horarios[i].id_materia == materias[j].abrev){

       printf("%i.Grupo %s Materia %s",i,horarios[i].grupo,materias[j].abrev);

      }else{
       printf("El profesor no tiene materias asignadas\n");

     }

     }  

      }else{

        printf("No hay un Usuario profesor\n");
      }

    }

  
    printf("Seleccione el grupo a elegir\n");
    scanf("%i",&op_listado);
    fflush(stdin);

}


 void perfil_profesor_menu_profesor(){
  int op;
  do{
  
   system("cls");
   printf ("Menu: \n");
   printf("-------------------------\n");
   printf("1.Lista de alumnos\n");
   printf("2.Cambiar de grupo\n");
   printf("3.Volver al menu general\n");
   printf("-------------------------\n");
   scanf("%i",&op);
   fflush(stdin);
   system("cls");

  }while(op<=0 || op>=4);

   switch (op)
   {
   case 1: perfil_profesor_menu_alum(); break;
   case 2: perfil_profesor_listados();break;
   case 3: perfil_profesor_menu_general();break;
   default: exit(-1); break;
   }
 

}

void perfil_profesor_menu_alum(){
  int op_alum;
 
  do{
   system("cls");
   printf ("Menu: Lista de alumnos\n");
   printf ("Alumno: -------------------\n");
   printf("----------------------------\n");
   printf("1.Ficha del alumno\n");
   printf("2.Calificaciones del alumno\n");
   printf("3.Volver\n");
   printf("----------------------------\n");
   

   scanf("%i",&op_alum);
   fflush(stdin);

  }while(op_alum <=0 || op_alum>=4);



   switch (op_alum)
   {
   case 1: break;
   case 2: break;
   case 3: perfil_profesor_menu_profesor();break;

   default: exit(-1); break;
   }

}


