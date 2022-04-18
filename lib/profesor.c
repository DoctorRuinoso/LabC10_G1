#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "profesor.h"
#include "core.h"


void perfil_profesor_menu_general(){

 perfil_profesor_listados();
 system("cls");
 perfil_profesor_menu_profesor();

}




int perfil_profesor_listados(){

  int op_listado,userp;

  printf("Listado de grupos y materias\n");
  printf("----------------------------\n");
  system("pause");
  
  userp = core_login();

  core_horarios_recovery();
  core_materias_recovery();
  

  for (int i = 0; i < configuration.horarios_counter;i++) {

      if (strcmp(horario[i].id_profesor,usuario[userp].id)==0){//Comprobamos que el profesor corresponde con el usuario logeado
      
      for(int j = 0; j<configuration.materias_counter;j++){
      
      if (strcmp(horario[i].id_materia,materia[j].id)==0){//Buscamos la materia que coincide en el horario para mostrarlo por pantalla

          printf("%i.Grupo %s Materia %s\n",i,horario[i].grupo,materia[j].abrev);//Imprimimos por pantalla los grupos,materias..
        }

      }
      
      }

      }
      

    

  
    printf("Seleccione el grupo a elegir\n"); //Seleccionamos el numero del grupo a elegir
    scanf("%i",&op_listado);
    fflush(stdin);
    
    return (op_listado);



}

//Cabecera:void perfil_profesor_menu_profesor()
//Precondicion:El profesor ha accedido al grupo seleccionado
//Postcondicion:El profesor ve la lista de alumnos o cambia el grupo correspondiente.

 void perfil_profesor_menu_profesor(){

  core_horarios_recovery();
  core_materias_recovery();

  int op;
  do{
  int grupo;
  grupo = perfil_profesor_listados();

   system("cls");
   printf ("Menu: \n");
    printf("%i.Grupo %s Materia %s\n",grupo,horario[grupo].grupo,materia[grupo].abrev);
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
   case 2: system("cls");perfil_profesor_listados();break;
   case 3: perfil_profesor_menu_general();break;
   default: exit(-1); break;
   }
 

}

//Cabecera:void perfil_profesor_menu_alum()
//Precondicion:El profesor  ha seleccionado la lista de alumnos
//Postcondicion:El profesor lee la ficha de los alumnos y las calificaciones

int perfil_profesor_menu_alum(){

core_alumnos_recovery();
core_horarios_recovery();
core_matriculas_recovery();
core_materias_recovery();

  int op_alum;
  int elecalum;
  int grupoalum;

  grupoalum = perfil_profesor_listados();
 
  do{
   system("cls");
   printf ("Menu: Lista de alumnos\n");
   
   for(int i=0 ;i<configuration.alumnos_counter;i++)
   {
     if (strcmp(horario[grupoalum].grupo,alumno[i].grupo)){
        printf("%i.%s\n",i,alumno[i].nombre);
     }
   }


    printf("Seleccione el alumno a elegir\n");
    scanf("%i",&elecalum);
    fflush(stdin);
    
    system("cls");


   
   printf ("Alumno: %i\n",alumno[elecalum].nombre);
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
   case 1: perfil_profesor_ficha_alumno();break;
   case 2: perfil_profesor_calif_alumno();break;
   case 3: perfil_profesor_menu_profesor();break;

   default: exit(-1); break;
   }

return elecalum;
}




void perfil_profesor_ficha_alumno(){
int elec,op;
elec = perfil_profesor_menu_alum();
printf("Alumno %s Dirección %s Grupo %s Curso %s\n",alumno[elec].nombre,alumno[elec].direc,alumno[elec].grupo,alumno[elec].curso);



  do{


   system("cls");
   printf("-------------------------\n");
   printf("1.Modificar datos alumno\n");
   printf("2.Volver a ver la ficha\n");
   printf("3.Volver al menu general\n");
   printf("-------------------------\n");
   scanf("%i",&op);
   fflush(stdin);
   system("cls");
   
 

  }while(op<=0 || op>=4);

   switch (op)
   {
   case 1:perfil_profesor_modificar_alumno();  break;
   case 2: perfil_profesor_ficha_alumno();break;
   case 3: perfil_profesor_menu_general();break;
   default: exit(-1); break;
   }


}


void perfil_profesor_calif_alumno(){
core_calificaciones_recovery();
int op_calif,elec_calif,op;
op_calif = perfil_profesor_listados();
elec_calif = perfil_profesor_menu_alum();

for(int i=0; i<configuration.calificaciones_counter;i++)
{
if(strcmp(alumno[elec_calif].id,nota[i].id_alum)==0){
 printf("Alumno %s Nota %s",alumno[elec_calif].nombre,nota[i].valor);
}
}



  do{


   system("cls");
   printf("-------------------------\n");
   printf("1.Modificar calificacion\n");
   printf("2.Annadir calificacion\n");
   printf("3.Borrar calificacion\n");
   printf("4.Volver a ver la ficha\n");
   printf("5.Volver al menu general\n");
   printf("-------------------------\n");
   scanf("%i",&op);
   fflush(stdin);
   system("cls");
   
 

  }while(op<=0 || op>=4);

   switch (op)
   {
   case 1:perfil_profesor_modificar_calif();break;
   case 2:perfil_profesor_annadir_calif();break;
   case 3:perfil_profesor_borrar_calif(); break;
   case 4: perfil_profesor_ficha_alumno();break;
   case 5: perfil_profesor_menu_general();break;
   default: exit(-1); break;
   }






}

void perfil_profesor_modificar_alumno()
{
  int op,elec_calif;
  elec_calif = perfil_profesor_menu_alum();
    do{


   system("cls");
   printf("-------------------------\n");
   printf("1.Modificar direccion\n");
   printf("2.Modificar Curso\n");
   printf("3.Modificar Grupo\n");
   printf("4.Volver a ver la ficha\n");
   printf("5.Volver al menu general\n");
   printf("-------------------------\n");
   scanf("%i",&op);
   fflush(stdin);
   system("cls");
   
 

  }while(op<=0 || op>=4);

   switch (op)
   {
   case 1: printf("%i\n",alumno[elec_calif].direc);fgets(alumno[elec_calif].direc,30,stdin);core_alumnos_update();break;
   case 2: printf("%i\n",alumno[elec_calif].curso);fgets(alumno[elec_calif].curso,30,stdin);core_alumnos_update();break;
   case 3: printf("%i\n",alumno[elec_calif].grupo);fgets(alumno[elec_calif].grupo,30,stdin);core_alumnos_update();break;
   case 4: perfil_profesor_ficha_alumno();break;
   case 5: perfil_profesor_menu_general();break;
   default: exit(-1); break;
   }

}

void perfil_profesor_modificar_calif()
{
core_calificaciones_recovery();
core_alumnos_recovery();
int elec_calif;
elec_calif = perfil_profesor_menu_alum();

for(int i=0; i<configuration.calificaciones_counter;i++)
{
if(strcmp(alumno[elec_calif].id,nota[i].id_alum)==0){
 printf("Nota %s\n",nota[i].valor);
 scanf("%f",nota[i].valor); core_calificaciones_update();
}
}

}

void perfil_profesor_annadir_calif()
{
int elec_calif;
float nueva_nota;
elec_calif = perfil_profesor_menu_alum();
core_calificaciones_recovery();
core_alumnos_recovery();

for(int i=0; i<configuration.calificaciones_counter;i++)
{
if(strcmp(alumno[elec_calif].id,nota[i].id_alum)==0){
printf("Introduzca la nueva nota");
scanf("%f",nueva_nota);
fflush(stdin);
nota[i].valor = nueva_nota;
core_calificaciones_update();
}
}

}

void perfil_profesor_borrar_calif()
{
int elec_calif;
elec_calif = perfil_profesor_menu_alum();
core_calificaciones_recovery();
core_alumnos_recovery();

for(int i=0; i<configuration.calificaciones_counter;i++)
{
if(strcmp(alumno[elec_calif].id,nota[i].id_alum)==0){
nota[i].valor = -1;
core_calificaciones_update();
}
}

}