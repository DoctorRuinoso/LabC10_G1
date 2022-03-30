//FUNCIONES ALUMNO Y HORARIOS DEL MODULO ADMINISTRADOR

#include "administrador_alumnohorario.h"

//Cabecera: void menu_administrador()
//Precondición: El usuario que entra al sistema es un administrador
//Postcondición: Dirige al administrador hacia la funcion que quiere hacer.
void menu_administrador(){
    int opc;
    do{                     //Muestra el menu de administrador
        printf(" ____________________________________________________________\n |Menu:Administrador                                        |\n |----------------------------------------------------------|\n |                  1.Usuario                               |\n |                  2.Alumnos                               |\n |                  3.Materias                              |\n |                  4.Horarios                              |\n |__________________________________________________________|\n");
        scanf("%i",&opc);
    }while(opc<1 || opc>4);             //no sale hasta que el numero introducido sea valido
    switch(opc){                           //depende del numero introducido se hara una funcion o otra

        case 1: opcion_usuario();break;
        case 2: opcion_alumnos();break;
        case 3: opcion_materias();break;
        case 4: opcion_horarios();break;
    }
}

//Cabecera: void opcion_alumnos()
//Precondición: El administrador pulsa la opcion alumnos.
//postcondición: Dirige al administrador hacia la funcion que quiere hacer con los alumnos
void opcion_alumnos(){
    system("cls");          //Limpia la pantalla
    int opc, salida=0;
    do{
        printf("Seleccione que opcion desea\n 1.Dar de alta alumno\n 2.Dar de baja alumno\n 3.Modificar alumno\n 4.Listar alumnos y seleccionar uno para administrarlo \n 5. Salir\n");     //Muestra el menu de la opcion alumno
        scanf("%i",&opc);
        switch(opc){                            //depende del numero introducido se hara una funcion o otra
            case 1: alta_alumno();break;
            case 2: baja_alumno();break;
            case 3: modificar_alumno();break;
            case 4: listar_alumnos();break;
            case 5: salida=1;break;
        }
    }while(opc<1 || opc>5 && salida==0);    //no sale hasta que el numero introducido sea valido
}

//Cabecera: void opcion_horarios()
//Precondición: El administrador pulsa la opcion horarios.
//Postcondición: Dirige al administrador hacia la funcion que quiere hacer con los horarios
void opcion_horarios(){
    system("cls");          //Limpia la pantalla
    int opc,id_prof,salida=0;
    printf("Escribe el identificador de profesor existente para gestionar sus horarios");
    scanf("%i",&id_prof);
    do{
        printf("Seleccione que opcion desea\n 1.Añadir horas de clasede un profesor\n 2.Eliminar horas de clase de un profesor\n 3.Modificar horas de clase de un profesor\n 4.Listar horarios de cada profesor \n 5. Salir\n"); //Muestra el menu de la opcion horarios
        scanf("%i",&opc);
        switch(opc){                                    //depende del numero introducido se hara una funcion o otra
            case 1: anadir_horas(id_prof);break;
            case 2: eliminar_horas(id_prof);break;
            case 3: modificar_horarios(id_prof);break;
            case 4: listar_horarios(id_prof);break;
            case 5: salida=1;break;
        }
    }while(opc<1 || opc>5 && salida==0);            //no sale hasta que el numero introducido sea valido
}

//Cabecera: void alta_alumno()
//Precondición: El administrador pulsa la opcion alta alumno.
//Postcondición: Se da de alta a un alumno
void alta_alumno(){
    printf("Escriba el id del alumno\n");                           // se le pide el id de alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].id,10,stdin);       //lee el id por teclado
    printf("Escriba el nombre del alumno\n");                       //se le pide el nombre de alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].nombre,30,stdin);   //lee el nombre por teclado
    printf("Escriba la direccion del alumno\n");                    // se le pide la direccion del alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].direc,30,stdin);    //lee la direccion por teclado
    printf("Escriba la localidad del alumno\n");                    //se le pide la localidad del alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].local,30,stdin);    //lee la localidad por teclado
    printf("Escriba el curso al que pertenece el alumno\n");        //se le pide el curso del alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].curso,30,stdin);    //lee el curso por teclado
    printf("Escriba el grupo del alumno\n");                        //se le pide el grupo al alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].grupo,10,stdin);    //lee el grupo por teclado
    configuration.alumnos_counter++;
    system("cls");          //Limpia la pantalla
}

//Cabecera: void baja_alumno()
//Precondición: El administrador pulsa la opcion baja alumno.
//Postcondición: Se da de baja a un alumno
void baja_alumno(){
    char id[6];
    int j=0;
    printf("Escriba el id del alumno que desea dar de baja\n");
    fflush(stdin);
    fgets(id,6,stdin);


    for(i=0;i<configuration.alumnos_counter;i++){
        if(strcmp(id,alumno[i].id)==0){                     // si el id del alumno coincide con el que se quiere dar de baja no lo escribe en la estructuta
            i++;
        }
        else{                                               //reescribe la estructura sin el alumno que se le quiere dar de baja
            strcpy(alumno[j].id,alumno[i].id);
            strcpy(alumno[j].nombre=alumno[i].nombre);
            strcpy(alumno[j].direc=alumno[i].direc);
            strcpy(alumno[j].local=alumno[i].local);
            strcpy(alumno[j].curso=alumno[i].curso);
            strcpy(alumno[j].grupo=alumno[i].grupo);
            j++;
        }
    }
    configuration.alumnos_counter=configuration.alumnos_counter-1;
}

//Cabecera: void modificar_alumno()
//Precondición: El administrador pulsa la opcion modificar alumno.
//Postcondición: Se modifica un campo concreto de un alumno.
void modificar_alumno(){
    int i,elec;
    char id[6];
    for(i=0;i<configuration.alumnos_counter;i++){
        printf("%s-",alumno[i].id); // Escribe el identificador
        printf("%s-",alumno[i].nombre); // Escribe el nombre
        printf("%s-",alumno[i].direc); // Escribe la direccion
        printf("%s-",alumno[i].local); // Escribe el la localidad
        printf("%s-",alumno[i].curso); // Escribe el curso al que pertenece
        printf("%s\n",alumno[i].grupo); // Escribe el grupo
        }
    printf("Escriba el id de alumno segun la lista que desea cambiar\n");       //se le pide el id del alumno a modificar
    fflush(stdin);
    fgets(id,6,stdin);
    for(i=0;i<configuration.alumnos_counter;i++){
        if(strcmp(id,alumno[i].id)==0){
            printf("Escribe que quieres cambiar\n 1. Identificador\n 2.Nombre\n 3.Direccion\n 4.Localidad\n 5.Curso\n 6. Grupo\n");
            scanf("%i",&elec);
            switch(elec){               //segun la eleccion se modificara un campo o otro
                case 1: printf("Escribe su nuevo identificador\n");fflush(stdin); fgets(alumno[i].id,6,stdin); break;
                case 2: printf("Escribe su nuevo nombre\n");fflush(stdin); fgets(alumno[i].nombre,30,stdin); break;
                case 3: printf("Escribe su nueva direccion\n");fflush(stdin); fgets(alumno[i].direc,30,stdin); break;
                case 4: printf("Escribe su nueva localidad\n");fflush(stdin); fgets(alumno[i].local,30,stdin); break;
                case 5: printf("Escribe su nuevo curso\n");fflush(stdin); fgets(alumno[i].curso,30,stdin); break;
                case 6: printf("Escribe su nuevo grupo\n");fflush(stdin); fgets(alumno[i].grupo,10,stdin); break;
                default: break;
            }
            exit(-1);
        }

    }

}


//Cabecera: void listar_alumnos()
//Precondición: El administrador pulsa la opcion listar alumno.
//Postcondición: Se listan todos los alumnos y si el administrador lo desea puede seleccionar un id de alumno y trabajar con datos de sus matriculas y materias.
void listar_alumnos(){
    int i,aux,id;
    printf("Los alumnos son:\n");
    for(i=0;i<configuration.alumnos_counter;i++){
        printf("%s-",alumno[i].id); // Escribe el identificador
        printf("%s-",alumno[i].nombre); // Escribe el nombre
        printf("%s-",alumno[i].direc); // Escribe la direccion
        printf("%s-",alumno[i].local); // Escribe el la localidad
        printf("%s-",alumno[i].curso); // Escribe el curso al que pertenece
        printf("%s\n",alumno[i].grupo); // Escribe el grupo

        }
            printf("\n Si desea modificar los datos de un alumno escriba su identificador, si no quiere modificar ningun alumno pulse 0\n");        // se le pide el identificador del alumno del que desea ver
            scanf("%i",&aux);
            if(aux!=0){
                for(i=0;i<configuration.alumnos_counter;i++){
                    if(aux=alumno.identificador){
                        do{
                            print("Seleccione la que desea hacer con este alumno:\n 1.Mostrar materias de las que se encuentra matriculado \n 2.Realizar cambios en matricula\n 3.Eliminar matricula\n 4.Crear nueva matricula\n 5.Salir\n");
                            scanf("%i",&opc);
                            switch(opc){                        //segun la eleccion se hara una funcion
                                case 1: listar_materias(aux);break;
                                case 2: modificar_matricula(aux);break;
                                case 3: eliminar_matricula(aux);break;
                                case 4: crear_matricula(aux);break;
                                case 5: salida=1;break;
                            }

                        }while(opc<1 || opc>5 && salida==0);        //no sale hasta que el numero introducido sea valido
                        i=configuration.alumnos_counter+1;
                    }
                }
            }
}


//Cabecera: void listar_materias(int id_alumno)
//Precondición: Id_alumno inicializado.
//Postcondición: Se listan las materias de un alumno concreto.
void listar_materias(int id_alumno){
    int i;
     for(i=0;i<configuration.materias_counter;i++){
            if(id_alumno==matricula[i].id_alum){
                    printf("%s-",materia[i].id); // Escribe el identificador
                    printf("%s-",materia[i].nombre); // Escribe el nombre
                    printf("%s\n",materia[i].abrev); // Escribe la abreviatura
            }
        }
}


//Cabecera: void modificar_matricula(int id_alumno)
//Precondición: Id_alumno inicializado.
//Postcondición: Se modifica la matricula de un alumno concreto.
void modificar_matricula(int id_alumno){
    int i,id_materia,id_materia_nueva;
    printf("Escribe el identificador de la materia la cual quieres modificar en la matricula del alumno");      //se le pide el identificador de materia
    scanf("%i",&id_materia);
    printf("Escribe el identificador de la nueva materia");      //se le pide el identificador de materia
    scanf("%i",&id_materia_nueva);
    for(i=0;i<configuration.matriculas_counter;i++){
        if(id_alum==matricula[i].id_alum && id_materia==matricula[i].id_materia ){
            matricula[i].id_materia=id_materia_nueva;
        }
    }
}

//Cabecera: void eliminar_matricula(int id_alumno)
//Precondición: Id_alumno inicializado.
//Postcondición: Se elimina la matricula seleccionada de un alumno concreto.
void eliminar_matricula(int id_alumno){
    int i,j,id_materia;
    printf("Escribe el identificador de la materia la cual quieres eliminar en la matricula del alumno");   //se le pide el identificador de materia
    scanf("%i",&id_materia);
    for(i=0;i<configuration.matriculas_counter;i++){
        if(id_materia==matricula[i].id_materia && id_alumno==matricula[i].id_alum){         // reescribe la estructura excepto la que se quiere eliminar
            i++;
        }
        else{
            matricula[j].id_alum=matricula[i].id_alum;
            matricula[j].id_materia=matricula[i].materia;
            j++;
        }
    }
    configuration.matriculas_counter=configuration.matriculas_counter-1;
}


//Cabecera: void crear_matricula(int id_alumno)
//Precondición: Id_alumno inicializado.
//Postcondición: Se crea una matricula de un alumno concreto.
void crear_matricula(int id_alumno){
    int id_materia;
    printf("Escribe el identificador de la materia la cual quieres añadir en la matricula del alumno");     //Se le pide el identificador de materia
    scanf("%i",&id_materia);
    matricula[configuration.matriculas_counter].id_alum=id_alum;                //Se le asignan los valores
    matricula[configuration.matriculas_counter].id_materia=id_materia;
    configuration.matriculas_counter++;
}

//Cabecera: void añdir_horas(int id_prof)
//Precondición: Id_prof ya inicializado.
//Postcondición: Se añade un horario al profesor seleccionado.
void anadir_horas(int id_prof){
    horario[configuration.horarios_counter].id_profesor=id_prof;
    printf("Escriba el dia de clase\n");                            //Pide el dia de clase
    scanf("%i",horario[configuration.horarios_counter].dia_clase);  // Lo alamacena en la estructura
    printf("Escriba la hora de clase\n");                           //Pide la hora de clase
    scanf("%i",horario[configuration.horarios_counter].hora_clase); // Lo alamacena en la estructura
    printf("Escriba el id de materia\n");                           //Pide el id de materia
    fflush(stdin);
    fgets(horario[configuration.horarios_counter].id_materia,4,stdin);// Lo alamacena en la estructura
    printf("Escriba el curso al que pertenece el alumno\n");        //Pide el curso
    fflush(stdin);
    fgets(horario[configuration.horarios_counter].grupo,10,stdin);  // Lo alamacena en la estructura
    configuration.horarios_counter++;
}

//Cabecera: void eliminar_horas(int id_prof)
//Precondición: Id_prof ya inicializado.
//Postcondición: Se elimina el horario seleccionado del profesor seleccionado.
void eliminar_horas(int id_prof){
    int j,dia,hora,id_materia;
    char grupo[10];
    printf("Escriba el dia de clase que desea eliminar\n");     //pide los datos del horario a eliminar y el usuario los escribe
    scanf("%i",&dia);
    printf("Escriba la hora de clase que desea eliminar\n");
    scanf("%i",&hora);
    printf("Escriba el id de materia que desea eliminar\n");
    scanf("%i",&id_materia);
    printf("Escriba el grupo de la clase que desea eliminar\n");
    fflush(stdin);
    fgets(grupo,10,stdin);

    for(i=0;i<configuration.horarios_counter;i++){              // reescribe la estructura excepto la que se quiere eliminar
        if(id_prof==horario[i].id_profesor && dia==horario[i].dia_clase && hora==horario[i].hora_clase && id_materia==horario[i].id_materia && strcmp(grupo,horario[i].grupo)==0){
            i++;
        }
        else{
            horario[j].id_profesor=horario[i].id_profesor;
            horario[j].dia_clase=horario[i].dia_clase;
            horario[j].hora_clase=horario[i].hora_clase;
            horario[j].id_materia=horario[i].id_materia;
            strcpy(horario[j].grupo,horario[i].grupo);
            j++;
        }
    }
    configuration.horarios_counter=configuration.horarios_counter-1;
}

//Cabecera: void modificar_horarios(int id_prof)
//Precondición: Id_prof ya inicializado.
//Postcondición: Se modifica un campo del horario del profesor seleccionado.
void modificar_horarios(int id_prof){
    int elec,dia,hora,id_materia;
    char grupo[10];
    printf("Escriba el dia de clase que desea modificar\n");        //pide los datos del horario a modificar y el usuario los escribe
    scanf("%i",&dia);
    printf("Escriba la hora de clase que desea modificar\n");
    scanf("%i",&hora);
    printf("Escriba el id de materia que desea modificar\n");
    scanf("%i",&id_materia);
    printf("Escriba el grupo de la clase que desea modificar\n");
    fflush(stdin);
    fgets(grupo,10,stdin);
    for(i=0;i<configuration.horarios_counter;i++){
        if(id_prof==horario[i].id_profesor && dia==horario[i].dia_clase && hora==horario[i].hora_clase && id_materia==horario[i].id_materia && strcmp(grupo,horario[i].grupo)==0){
            printf("Escribe que campo desea modificar\n 1. Dia\n 2.hora\n 3.Id materia\n 4.Grupo\n");       //Selecciona el cambio que quiere cambiar
            scanf("%i",&elec);
            switch(elec){                   //Segun la eleccion cambia un campo o otro
                case 1:printf("Escriba el nuevo dia\n");scanf("%i",horario[i].dia_clase);break;
                case 2:printf("Escriba la nueva hora de clase\n");scanf("%i",horario[i].hora_clase);break;
                case 3:printf("Escriba el nuevo id de materia\n");scanf("%i",horario[i].id_materia);break;
                case 4: printf("Escriba el nuevo grupo\n"); fflush(stdin); fgets(horario[i].grupo,10,stdin);break;
                default: exit(-1);
            }
        }
    }
}


//Cabecera: void listar_horarios(int id_prof)
//Precondición: Id_prof ya inicializado.
//Postcondición: Se listan los horarios del profesor seleccionado.
void listar_horarios(int id_prof){
    int i;
     for(i=0;i<configuration.horarios_counter;i++){
            if(id_prof==horario[i].id_profesor){
                printf("%s-",horario[i].id_profesor); // Escribe el identificador
                printf("%i-",horario[i].dia_clase); // Escribe el dia de clase
                printf("%i-",horario[i].hora_clase); // Escribe la hora de clase
                printf("%s-",horario[i].id_materia);    //Escribe el id de materia
                printf("%s\n",horario[i].grupo);        //Escribe el grupo
            }
        }
}


