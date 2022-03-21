//FUNCIONES ALUMNO Y HORARIOS DEL MODULO ADMINISTRADOR

#include "administrador_alumnohorario.h"

void menu_administrador(){
    int opc;
    do{
        printf(" ____________________________________________________________\n |Menu:Administrador                                        |\n |----------------------------------------------------------|\n |                  1.Usuario                               |\n |                  2.Alumnos                               |\n |                  3.Materias                              |\n |                  4.Horarios                              |\n |__________________________________________________________|\n");
        scanf("%i",&opc);
    }while(opc<1 || opc>4);ç
    switch(opc){
        case 1: opcion_usuario();break;
        case 2: opcion_alumnos();break;
        case 3: opcion_materias();break;
        case 4: opcion_horarios();break;
    }
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
    }while(opc<1 || opc>5 && salida==0);
}

void opcion_horarios(){
    int opc, salida=0;
    do{
        printf("Seleccione que opcion desea\n 1.Añadir horas de clasede un profesor\n 2.Eliminar horas de clase de un profesor\n 3.Modificar horas de clase de un profesor\n 4.Listar horarios de cada profesor \n 5. Salir\n");
        scanf("%i",&opc);
        switch(opc){
            case 1: anadir_horas();break;
            case 2: eliminar_horas();break;
            case 3: modificar_horarios();break;
            case 4: listar_horarios();break;
            case 5: salida=1;break;
        }
    }while(opc<1 || opc>5 && salida==0);
}

void alta_alumno(){
    printf("Escriba el id del alumno\n");
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].id,10,stdin);
    printf("Escriba el nombre del alumno\n");
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].nombre,30,stdin);
    printf("Escriba la direccion del alumno\n");
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].direc,30,stdin);
    printf("Escriba la localidad del alumno\n");
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].local,30,stdin);
    printf("Escriba el curso al que pertenece el alumno\n");
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].curso,30,stdin);
    printf("Escriba el grupo del alumno\n");
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].grupo,10,stdin);
    configuration.alumnos_counter++;
}
void baja_alumno(){
    char id[6];
    int j=0;
    printf("Escriba el id del alumno que desea dar de baja\n");
    fflush(stdin);
    fgets(id,6,stdin);


    for(i=0;i<configuration.alumnos_counter;i++){
        if(strcmp(id,alumno[i].id)==0){
            i++;
        }
        else{
            strcpy(alumno[j].id,alumno[i].id);
            strcpy(alumno[j].nombre=alumno[i].nombre);
            strcpy(alumno[j].direc=alumno[i].direc);
            strcpy(alumno[j].local=alumno[i].local);
            strcpy(alumno[j].curso=alumno[i].curso);
            strcpy(alumno[j].grupo=alumno[i].grupo);
        }
    }
    configuration.alumnos_counter=configuration.alumnos_counter-1;
}
void modificar_alumno(){

}

void listar_alumnos(){
    int i,aux,id;
    printf("Los alumnos son:\n");
    for(i=0;i<configuration.alumnos_counter;i++){
        printf("%i-",alumno[i].id); // Escribe el identificador
        printf("%s-",alumno[i].nombre); // Escribe el nombre
        printf("%s-",alumno[i].direc); // Escribe la direccion
        printf("%s-",alumno[i].local); // Escribe el la localidad
        printf("%s-",alumno[i].curso); // Escribe el curso al que pertenece
        printf("%s\n",alumno[i].grupo); // Escribe el grupo

        }
            printf("\n Si desea modificar los datos de un alumno escriba su identificador, si no quiere modificar ningun alumno pulse 0\n");
            scanf("%i",&aux);
            if(aux!=0){
                for(i=0;i<configuration.alumnos_counter;i++){
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

                        }while(opc<1 || opc>5 && salida==0);
                        i=configuration.alumnos_counter+1;
                    }
                }
            }
}

void listar_materias(int id){
    int i;
     for(i=0;i<contadormatriculas;i++){
            if(id=matricula.idescolar){
                    printf("%i-",materia[i].id); // Escribe el identificador
                    printf("%s-",materia[i].nombre); // Escribe el nombre
                    printf("%s\n",materia[i].abrev); // Escribe la abreviatura
            }
        }
}


void modificar_matricula(int id){

}
void eliminar_matricula(int id){

}
void crear_matricula(int id){

}
void anadir_horas(){

}
void eliminar_horas(){

}
void modificar_horarios(){

}
void listar_horarios(){

}


