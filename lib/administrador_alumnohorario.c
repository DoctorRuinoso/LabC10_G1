//FUNCIONES ALUMNO Y HORARIOS DEL MODULO ADMINISTRADOR

#include "administrador_alumnohorario.h"


void menu_administrador(){
    int opc;
    do{
        printf(" ____________________________________________________________\n |Menu:Administrador                                        |\n |----------------------------------------------------------|\n |                  1.Usuario                               |\n |                  2.Alumnos                               |\n |                  3.Materias                              |\n |                  4.Horarios                              |\n |__________________________________________________________|\n");
        scanf("%i",&opc);
    }while(opc<0 || opc>4);
}


void opcion_alumnos(){
    int opc, salida=0;
    do{
        printf("Seleccione que opcion desea\n 1.Dar de alta alumno\n 2.Dar de baja alumno\n 3.Modificar alumno\n 4.Listar alumnos y seleccionar uno para administrarlo \n 5. Salir\n");
        scanf("%i",&opc);
        switch(opc){
            case 1: alta_alumno();break;
            case 2: baja_alumno();break;
            case 3: modificar_alumno();break;
            case 4: listar_alumnos();break;
            case 5: salida=1;break;
        }
    }while(opc<0 || opc>5 && salida==0);
}

void opcion_horarios(){
    int opc, salida=0;
    do{
        printf("Seleccione que opcion desea\n 1.Añadir horas de clasede un profesor\n 2.Eliminar horas de clase de un profesor\n 3.Modificar horas de clase de un profesor\n 4.Listar horarios de cada profesor \n 5. Salir\n");
        scanf("%i",&opc)
        switch(opc){
            case 1: añadir_horas();break;
            case 2: eliminar_horas();break;
            case 3: modificar_horarios();break;
            case 4: listar_horarios();break;
            case 5: salida=1;break;
        }
    }while(opc<0 || opc>5 && salida==0);
}

void listar_alumnos(){
    int i,aux,id;
    printf("Los alumnos son:\n");
    for(i=0;i<contadoralumno;i++){
        printf("%i-",); // Escribe el identificador
        printf("%s-",); // Escribe el nombre
        printf("%s-",); // Escribe la direccion
        printf("%s-",); // Escribe el la localidad
        printf("%s-",); // Escribe el curso al que pertenece
        printf("%s\n",); // Escribe el grupo

        }
            printf("\n Si desea modificar los datos de un alumno escriba su identificador, si no quiere modificar ningun alumno pulse 0");
            scanf("%i",&aux);
            if(aux!=0){
                for(i=0;i<contadoralumno;i++){
                    if(aux=alumno.identificador){
                        do{
                            print("Seleccione la que desea hacer con este alumno:\n 1.Mostrar materias de las que se encuentra matriculado \n 2.Realizar cambios en matricula\n 3.Eliminar matricula\n 4.Crear nueva matricula\n 5.Salir\n");
                            scanf("%i",&opc);
                            switch(opc){
                                case 1: listar_materias(aux);break;
                                case 2: modificar_matricula(aux);break;
                                case 3: eliminar_matricula(aux);break;
                                case 4: crear_matricula(aux);break;
                                case 5: salida=1;break;
                            }

                        }while(opc<0 || opc>5 && salida==0);
                        i=contadoralumno+1;
                    }
                }
            }
}

void listar_materias(int id){
    int i;
     for(i=0;i<contadormatriculas;i++){
            if(id=matricula.idescolar){
                    printf("%i-",); // Escribe el identificador
                    printf("%s-",); // Escribe el nombre
                    printf("%s\n",); // Escribe la abreviatura
            }
        }
}
