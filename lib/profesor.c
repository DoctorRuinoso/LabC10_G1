#include <stdio.h>
#include <stdlib.h>
#include "core.h"





void perfil_profesor_menu_general(){

 perfil_profesor_listados();
 system("cls");
 perfil_profesor_menu_profesor();

}




int perfil_profesor_listados(){

  int op_listado;

  printf("Listado de grupos y materias\n");
  printf("----------------------------\n");
  system("pause");
  

  core_horarios_recovery();

  for (int i = 0; i < configuration->horarios_counter;i++) {

      if (horario[i].id_profesor==usuario[1].id){//Buscamos un horario en el que este el profesor asignado

     for(int j=0; j<configuration->matriculas_counter;j++){
      
      if (horario[i].id_materia == matricula[j].id_materia){//Buscamos la materia que coincide en el horario

        for(int k=0;k<configuration->horarios_counter;k++){
        
        if(matricula[j].id_materia == materia[k].id){//Buscamos el id de la materia de la matricula

          printf("%i.Grupo %s Materia %s\n",i,horario[i].grupo,materia[k].abrev);//Imprimimos por pantalla los grupos,materias..
        }
        

        }
      

      }else{
       printf("El profesor no tiene materias asignadas\n");

     }

     }  

      }else{
        printf("El profesor no tiene ningún horario asignado\n");
      }

    }

  
    printf("Seleccione el grupo a elegir\n");
    scanf("%i",&op_listado);
    fflush(stdin);
    
    return (op_listado);



}

//Cabecera:void perfil_profesor_menu_profesor()
//Precondicion:El profesor ha accedido al grupo seleccionado
//Postcondicion:El profesor ve la lista de alumnos o cambia el grupo correspondiente.

 void perfil_profesor_menu_profesor(){
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
   case 2: perfil_profesor_listados();break;
   case 3: perfil_profesor_menu_general();break;
   default: exit(-1); break;
   }
 

}

//Cabecera:void perfil_profesor_menu_alum()
//Precondicion:El profesor  ha seleccionado la lista de alumnos
//Postcondicion:El profesor lee la ficha de los alumnos y las calificaciones

int perfil_profesor_menu_alum(){
  int op_alum;
  int grupoalum,elecalum;
  grupoalum = perfil_profesor_listados();
 
  do{
   system("cls");
   printf ("Menu: Lista de alumnos\n");

  for(int i=0;i<configuration->alumnos_counter;i++){
    if(alumno[i].grupo ==grupoalum){
      printf("%i.El nombre es %i\n",i,alumno[i].nombre);
    }
  }

    printf("Seleccione el alumno a elegir\n");
    scanf("%i",&elecalum);
    fflush(stdin);
    


   
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
   case 1: break;perfil_profesor_ficha_alumno();break;
   case 2: break;perfil_profesor_calif_alumno();
   case 3: perfil_profesor_menu_profesor();break;

   default: exit(-1); break;
   }

}




void perfil_profesor_ficha_alumno(){
int op_ficha,elec;
op_ficha = perfil_profesor_listados();
elec = perfil_profesor_menu_alum();

printf("Alumno %i\n",alumno[op_ficha].nombre[elec]);


}


void perfil_profesor_calif_alumno(){
int op_calif,elec_calif;
op_calif = perfil_profesor_listados();
elec_calif = perfil_profesor_menu_alum();

printf("Alumno %i\n",nota[op_calif].valor);

}