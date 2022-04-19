#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"
#include "administrador.h"

//Cabecera: void menu_administrador()
//Precondición: el usuario ha seleccionado el perfil administrador.
//Postcondición: se muestran las opciones del menu administrador: usuarios, alumnos, materias, horarios.
void menu_administrador(int logged_user){
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
        scanf("%d", &opc);
        switch(opc){
            case 1: alta_usuario(); break; //Función implementada en core.c.
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
        scanf("%d", &opc);
        switch(opc){
            case 1: alta_materia(); break;
            case 2: baja_materia(); break;
            case 3: modificar_materia(); break;
            case 4: listar_materias(); break;
            case 5: salida=1; break;
        }//fin_switch
    }while(opc<1 || opc>5 && salida==0);//fin_do_while
}//fin_void

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
    int opc,salida=0;
    char id_prof[3];
    printf("Escribe el identificador de profesor existente para gestionar sus horarios\n");
    fflush(stdin);
    fgets(id_prof,4,stdin);
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


//Mini módulo Administrador - Usuarios

//Cabecera: void baja_usuario()
//Precondición: ninguna.
//Postcondición: elimina al usuario cuyo id ha sido seleccionado satisfactoriamente.
void baja_usuario(){
    int id, j = 0;
    printf("Escriba el id del usuario que desea dar de baja\n");
    fflush(stdin);
    scanf("%d", &id);


    for(int i = 0; i < configuration.usuarios_counter; ++i){
        if(id == usuario[i].id){                     // si el id del usuario coincide con el que se quiere dar de baja no lo escribe en la estructuta
            i++;
        }//fin_if
        else{                                               //reescribe la estructura sin el usuario que se le quiere dar de baja
            usuario[j].id = usuario[i].id;
            strcpy(usuario[j].nombre,usuario[i].nombre);
            strcpy(usuario[j].perfil,usuario[i].perfil);
            strcpy(usuario[j].name_tag,usuario[i].name_tag);
            strcpy(usuario[j].password,usuario[i].password);
            j++;
        }//fin_else
    }//fin_for
    configuration.usuarios_counter=configuration.usuarios_counter-1;
}//fin_void

//Cabecera: void modificar_usuario()
//Precondición: ninguna.
//Postcondición: modifica el campo seleccionado por el administrador para el usuario cuya id sea correspondiente satisfactoriamente.
void modificar_usuario(){
    int id, opcion;
    for(int i = 0; i < configuration.usuarios_counter; ++i){
        printf("%d-",usuario[i].id);        //Escribe el identificador
        printf("%s-",usuario[i].nombre);    //Escribe el nombre
        printf("%s-",usuario[i].perfil);    //Escribe el perfil
        printf("%s-",usuario[i].name_tag);  //Escribe el name_tag
        printf("%s-",usuario[i].password);  //Escribe la password
    }//fin_for

    printf("Introduce el ID del usuario a modificar: \n");       //se le pide el id del usuario a modificar.
    fflush(stdin);
    scanf("%d", &id);

    for(int i = 0; i < configuration.usuarios_counter; ++i){
        if(usuario[i].id == id){
            printf("Selecciona que quieres cambiar: \n");
            printf("1)Id\t\n2)Nombre\t\n3)Perfil\t\n4)Name Tag\t\n5)Password");
            scanf("%d",&opcion);
            switch(opcion){
                case 1:
                    printf("Introduce el Id\n");
                    scanf("%d", &usuario[i].id);
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
            core_usuarios_recovery();
        }//fin_if
    }//fin_for
}//fin_void

//Cabecera: void listar_usuarios()
//Precondición: ninguna.
//Postcondición: muestra por pantalla la lista de usuarios disponibles.
void listar_usuarios(){
    assert(USUARIOS_FILE!=NULL);
    for (int i = 0; i < configuration.usuarios_counter; ++i){
        printf("ID: %d\n", usuario[i].id);
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
    assert(configuration.materias_counter!=0 && "NO se ha leido correctamente el fichero");
    MATERIAS_FILE = fopen("data/materias.txt","a");
    assert(MATERIAS_FILE!=NULL && "No se ha podido iniciar el fichero de materias");

    materias temp_materias;
    printf("\n\tIntroduce los datos de la nueva materia: \n");
    printf("Id de la materia: ");
    scanf("%d", &temp_materias.id);
    printf("\nNombre de la materia: ");
    scanf("%s",temp_materias.nombre);
    printf("Abreviatura de la materia: ");
    scanf("%s",temp_materias.abrev);

    configuration.materias_counter++;
    materia = realloc(materia,configuration.materias_counter*sizeof(materias));
    materia[configuration.materias_counter-1].id = temp_materias.id;
    strcpy(materia[configuration.materias_counter-1].nombre,temp_materias.nombre);
    strcpy(materia[configuration.materias_counter-1].abrev,temp_materias.abrev);
    core_materias_update();
    core_materias_recovery();
}//fin_void

//Cabecera: void baja_materia()
//Precondición: ninguna.
//Postcondición: elimina la materia cuyo id ha sido seleccionado satisfactoriamente.
void baja_materia(){
    int id, j = 0;
    printf("Escriba el id de la materia que desea dar de baja: \n");
    fflush(stdin);
    scanf("%d", &id);


    for(int i = 0; i < configuration.materias_counter; ++i){
        if(id == materia[i].id){                     // si el id de la materia coincide con el que se quiere dar de baja no lo escribe en la estructuta
            i++;
        }
        else{                                               //reescribe la estructura sin la materia que se le quiere dar de baja
            materia[j].id = materia[i].id;
            strcpy(materia[j].nombre,materia[i].nombre);
            strcpy(materia[j].abrev,materia[i].abrev);
            j++;
        }
    }
    configuration.materias_counter=configuration.materias_counter-1;
}

//Cabecera: void modificar_materia()
//Precondición: ninguna.
//Postcondición: modifica el campo seleccionado por el administrador para la materia cuya id sea correspondiente satisfactoriamente.
void modificar_materia(){
    int id, opcion;
    for(int i = 0; i < configuration.materias_counter; ++i){
        printf("%d-",materia[i].id); //Escribe el identificador.
        printf("%s-",materia[i].nombre); //Escribe el nombre.
        printf("%s-",materia[i].abrev); //Escribe la abreviatura.
    }

    printf("Introduce el ID de la materia a modificar: \n");       //se le pide el id de la materia a modificar.
    fflush(stdin);
    scanf("%d", &id);

    for(int i = 0; i < configuration.materias_counter; ++i){
        if(id == materia[i].id){
            printf("Selecciona que quieres cambiar: \n");
            printf("1)Id\t\n2)Nombre\t\n3)Abreviatura");
            scanf("%d",&opcion);
            switch(opcion){
                case 1:
                    printf("Introduce el Id\n");
                    scanf("%d", &materia[i].id);
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
            core_materias_recovery();
        }
    }
}

//Cabecera: void listar_materias()
//Precondición: ninguna.
//Postcondición: muestra por pantalla la lista de materias disponibles.
void listar_materias(){
    assert(MATERIAS_FILE!=NULL);
    for (int i = 0; i < configuration.materias_counter; ++i){
        printf("ID: %d\n", materia[i].id);
        printf("Nombre de la materia: %s\n", materia[i].nombre);
        printf("Abreviatura: %s\n", materia[i].abrev);
    }
}

//Cabecera: void alta_alumno()
//Precondición: El administrador pulsa la opcion alta alumno.
//Postcondición: Se da de alta a un alumno
void alta_alumno(){
    printf("Escriba el id del alumno\n");                           // se le pide el id de alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].id,10,stdin);       //lee el id por teclado
    espacios_desc(alumno[configuration.alumnos_counter].id);
    printf("Escriba el nombre del alumno\n");                       //se le pide el nombre de alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].nombre,30,stdin);   //lee el nombre por teclado
    espacios_desc(alumno[configuration.alumnos_counter].nombre);
    printf("Escriba la direccion del alumno\n");                    // se le pide la direccion del alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].direc,30,stdin);    //lee la direccion por teclado
    espacios_desc(alumno[configuration.alumnos_counter].direc);
    printf("Escriba la localidad del alumno\n");                    //se le pide la localidad del alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].local,30,stdin);    //lee la localidad por teclado
    espacios_desc(alumno[configuration.alumnos_counter].local);
    printf("Escriba el curso al que pertenece el alumno\n");        //se le pide el curso del alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].curso,30,stdin);    //lee el curso por teclado
    espacios_desc(alumno[configuration.alumnos_counter].curso);
    printf("Escriba el grupo del alumno\n");                        //se le pide el grupo al alumno
    fflush(stdin);
    fgets(alumno[configuration.alumnos_counter].grupo,10,stdin);    //lee el grupo por teclado
    espacios_desc(alumno[configuration.alumnos_counter].grupo);
    configuration.alumnos_counter++;
    system("cls");          //Limpia la pantalla
    core_alumnos_update();
    core_alumnos_recovery();
}

//Cabecera: void baja_alumno()
//Precondición: El administrador pulsa la opcion baja alumno.
//Postcondición: Se da de baja a un alumno
void baja_alumno(){
    char id[6];
    int j=0,i;
    printf("Escriba el id del alumno que desea dar de baja\n");
    fflush(stdin);
    fgets(id,6,stdin);


    for(i=0;i<configuration.alumnos_counter;i++){
        if(strcmp(id,alumno[i].id)==0){                     // si el id del alumno coincide con el que se quiere dar de baja no lo escribe en la estructuta
            i++;
        }
        else{                                               //reescribe la estructura sin el alumno que se le quiere dar de baja
            strcpy(alumno[j].id,alumno[i].id);
            strcpy(alumno[j].nombre,alumno[i].nombre);
            strcpy(alumno[j].direc,alumno[i].direc);
            strcpy(alumno[j].local,alumno[i].local);
            strcpy(alumno[j].curso,alumno[i].curso);
            strcpy(alumno[j].grupo,alumno[i].grupo);
            j++;
        }
    }
    configuration.alumnos_counter=configuration.alumnos_counter-1;
    core_alumnos_update();
    core_alumnos_recovery();
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
                case 1: printf("Escribe su nuevo identificador\n");fflush(stdin); fgets(alumno[i].id,6,stdin);espacios_desc(alumno[configuration.alumnos_counter].id); break;
                case 2: printf("Escribe su nuevo nombre\n");fflush(stdin); fgets(alumno[i].nombre,30,stdin);espacios_desc(alumno[configuration.alumnos_counter].nombre); break;
                case 3: printf("Escribe su nueva direccion\n");fflush(stdin); fgets(alumno[i].direc,30,stdin);espacios_desc(alumno[configuration.alumnos_counter].direc); break;
                case 4: printf("Escribe su nueva localidad\n");fflush(stdin); fgets(alumno[i].local,30,stdin);espacios_desc(alumno[configuration.alumnos_counter].local); break;
                case 5: printf("Escribe su nuevo curso\n");fflush(stdin); fgets(alumno[i].curso,30,stdin);espacios_desc(alumno[configuration.alumnos_counter].curso); break;
                case 6: printf("Escribe su nuevo grupo\n");fflush(stdin); fgets(alumno[i].grupo,10,stdin);espacios_desc(alumno[configuration.alumnos_counter].grupo); break;
                default: break;
            }
            exit(-1);
        }
    }
    core_alumnos_update();
    core_alumnos_recovery();
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
            printf("\n Si desea modificar los datos de un alumno pulse 1, si no quiere modificar ningun alumno pulse 0\n");        // se le pide el identificador del alumno del que desea ver
            scanf("%i",&aux);
            if(aux!=0){
                printf("\n Escriba el id alumno\n");
                fflush(stdin);
                fgets(id,6,stdin);
                espacios_desc(id);
                for(i=0;i<configuration.alumnos_counter;i++){
                    if(strcmp(id,alumno[i].id)==0){
                        do{
                            print("Seleccione la que desea hacer con este alumno:\n 1.Mostrar materias de las que se encuentra matriculado \n 2.Realizar cambios en matricula\n 3.Eliminar matricula\n 4.Crear nueva matricula\n 5.Salir\n");
                            scanf("%i",&opc);
                            switch(opc){                        //segun la eleccion se hara una funcion
                                case 1: listar_materias_de_alumno(id);break;
                                case 2: modificar_matricula(id);break;
                                case 3: eliminar_matricula(id);break;
                                case 4: crear_matricula(id);break;
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
void listar_materias_de_alumno(char id_alumno[]){
    int i,j;
     for(i=0;i<configuration.matriculas_counter;i++){
            if(strcmp(id_alumno,matricula[i].id_alum)==0){
                    for(j=0;j<configuration.materias_counter;j++){
                        if(strcmp(materia[j].id,matricula[i].id_materia)==0){
                            printf("%s-",materia[i].id); // Escribe el identificador
                            printf("%s-",materia[i].nombre); // Escribe el nombre
                            printf("%s\n",materia[i].abrev); // Escribe la abreviatura
                        }
                    }
            }
        }
}


//Cabecera: void modificar_matricula(int id_alumno)
//Precondición: Id_alumno inicializado.
//Postcondición: Se modifica la matricula de un alumno concreto.
void modificar_matricula(char id_alumno[]){
    int i;
    char id_materia[4],id_materia_nueva[4];
    printf("Escribe el identificador de la materia la cual quieres modificar en la matricula del alumno");      //se le pide el identificador de materia
    fflush(stdin);
    fgets(id_materia,4,stdin);
    espacios_desc(id_materia);
    printf("Escribe el identificador de la nueva materia");      //se le pide el identificador de materia
    fflush(stdin);
    fgets(id_materia_nueva,4,stdin);
    espacios_desc(id_materia_nueva);
    for(i=0;i<configuration.matriculas_counter;i++){
        if(strcmp(id_alum,matricula[i].id_alum)==0 && strcmp(id_materia,matricula[i].id_materia)==0 ){
            strcpy(matricula[i].id_materia,id_materia_nueva);
        }
    }
    core_matriculas_update();
    core_matriculas_recovery();
}

//Cabecera: void eliminar_matricula(int id_alumno)
//Precondición: Id_alumno inicializado.
//Postcondición: Se elimina la matricula seleccionada de un alumno concreto.
void eliminar_matricula(char id_alumno[]){
    int i,j;
    char id_materia;
    printf("Escribe el identificador de la materia la cual quieres eliminar en la matricula del alumno");   //se le pide el identificador de materia
    fflush(stdin);
    fgets(id_materia,4,stdin);
    espacios_desc(id_materia);
    for(i=0;i<configuration.matriculas_counter;i++){
        if(strcmp(id_materia,matricula[i].id_materia)==0 && strcmp(id_alumno,matricula[i].id_alum)==0){         // reescribe la estructura excepto la que se quiere eliminar
            i++;
        }
        else{
            strcpy(matricula[j].id_alum,matricula[i].id_alum);
            strcpy(matricula[j].id_materia,matricula[i].materia);
            j++;
        }
    }
    configuration.matriculas_counter=configuration.matriculas_counter-1;
    core_matriculas_update();
    core_matriculas_recovery();
}



//Cabecera: void crear_matricula(int id_alumno)
//Precondición: Id_alumno inicializado.
//Postcondición: Se crea una matricula de un alumno concreto.
void crear_matricula(char id_alumno[]){
    char id_materia;
    printf("Escribe el identificador de la materia la cual quieres añadir en la matricula del alumno");     //Se le pide el identificador de materia
    fflush(stdin);
    fgets(id_materia,4,stdin);
    espacios_desc(id_materia);
    strcpy(matricula[configuration.matriculas_counter].id_alum,id_alum);                //Se le asignan los valores
    strcpy(matricula[configuration.matriculas_counter].id_materia,id_materia);
    configuration.matriculas_counter++;
    core_matriculas_update();
    core_matriculas_recovery();
}

//Cabecera: void añdir_horas(int id_prof)
//Precondición: Id_prof ya inicializado.
//Postcondición: Se añade un horario al profesor seleccionado.
void anadir_horas(char id_prof[]){
    id_prof[3]='\n';
    espacios_desc(id_prof);
    strcpy(horario[configuration.horarios_counter].id_profesor,id_prof);
    printf("Escriba el dia de clase\n");                            //Pide el dia de clase
    scanf("%i",&horario[configuration.horarios_counter].dia_clase);  // Lo alamacena en la estructura

    printf("Escriba la hora de clase\n");                           //Pide la hora de clase
    scanf("%i",&horario[configuration.horarios_counter].hora_clase); // Lo alamacena en la estructura

    printf("Escriba el id de materia\n");                           //Pide el id de materia
    fflush(stdin);
    fgets(horario[configuration.horarios_counter].id_materia,4,stdin);// Lo alamacena en la estructura
    espacios_desc(horario[configuration.horarios_counter].id_materia);

    printf("Escriba el curso al que pertenece el alumno\n");        //Pide el curso
    fflush(stdin);
    fgets(horario[configuration.horarios_counter].grupo,10,stdin);  // Lo alamacena en la estructura
    espacios_desc(horario[configuration.horarios_counter].grupo);
    configuration.horarios_counter++;
    core_horarios_update();
    core_horarios_recovery();
}


//Cabecera: void eliminar_horas(int id_prof)
//Precondición: Id_prof ya inicializado.
//Postcondición: Se elimina el horario seleccionado del profesor seleccionado.
void eliminar_horas(char id_prof[]){
    int i,j=0,dia,hora;
    char grupo[10], id_materia[4];
    id_prof[3]='\n';
    espacios_desc(id_prof);
    printf("Escriba el dia de clase que desea eliminar\n");     //pide los datos del horario a eliminar y el usuario los escribe
    scanf("%i",&dia);
    printf("Escriba la hora de clase que desea eliminar\n");
    scanf("%i",&hora);
    printf("Escriba el id de materia que desea eliminar\n");
    fflush(stdin);
    fgets(id_materia,4,stdin);
    espacios_desc(id_materia);
    printf("Escriba el grupo de la clase que desea eliminar\n");
    fflush(stdin);
    fgets(grupo,10,stdin);
    espacios_desc(grupo);

    for(i=0;i<configuration.horarios_counter;i++){              // reescribe la estructura excepto la que se quiere eliminar
        if(strcmp(id_prof,horario[i].id_profesor)==0 && dia==horario[i].dia_clase && hora==horario[i].hora_clase && strcmp(id_materia,horario[i].id_materia)==0 && strcmp(grupo,horario[i].grupo)==0){
            i++;
        }
        else{
            strcpy(horario[j].id_profesor,horario[i].id_profesor);
            horario[j].dia_clase=horario[i].dia_clase;
            horario[j].hora_clase=horario[i].hora_clase;
            strcpy(horario[j].id_materia,horario[i].id_materia);
            strcpy(horario[j].grupo,horario[i].grupo);
            j++;
        }
    }
    configuration.horarios_counter=configuration.horarios_counter-1;
    core_horarios_update();
    core_horarios_recovery();
}

//Cabecera: void modificar_horarios(int id_prof)
//Precondición: Id_prof ya inicializado.
//Postcondición: Se modifica un campo del horario del profesor seleccionado.
void modificar_horarios(char id_prof[]){
    int elec,dia,hora,i;
    char grupo[10],id_materia[4];
    id_prof[3]='\n';
    espacios_desc(id_prof);
    printf("Escriba el dia de clase que desea modificar\n");        //pide los datos del horario a modificar y el usuario los escribe
    scanf("%i",&dia);
    printf("Escriba la hora de clase que desea modificar\n");
    scanf("%i",&hora);
    printf("Escriba el id de materia que desea modificar\n");
    fflush(stdin);
    fgets(id_materia,10,stdin);
    espacios_desc(id_materia);
    printf("Escriba el grupo de la clase que desea modificar\n");
    fflush(stdin);
    fgets(grupo,10,stdin);
    espacios_desc(grupo);
    for(i=0;i<configuration.horarios_counter;i++){
        if(strcmp(id_prof,horario[i].id_profesor)==0 && dia==horario[i].dia_clase && hora==horario[i].hora_clase && strcmp(id_materia,horario[i].id_materia)==0 && strcmp(grupo,horario[i].grupo)==0){
            printf("Escribe que campo desea modificar\n 1. Dia\n 2.hora\n 3.Id materia\n 4.Grupo\n");       //Selecciona el cambio que quiere cambiar
            scanf("%i",&elec);
            switch(elec){                   //Segun la eleccion cambia un campo o otro
                case 1:printf("Escriba el nuevo dia\n");scanf("%i",&horario[i].dia_clase);break;
                case 2:printf("Escriba la nueva hora de clase\n");scanf("%i",&horario[i].hora_clase);break;
                case 3:printf("Escriba el nuevo id de materia\n");fflush(stdin);fgets(horario[i].id_materia,4,stdin);espacios_desc(horario[i].id_materia);break;
                case 4:printf("Escriba el nuevo grupo\n"); fflush(stdin); fgets(horario[i].grupo,10,stdin);espacios_desc(horario[i].grupo);break;
                default: exit(-1);
            }
        }
    }
    core_horarios_update();
    core_horarios_recovery();
}


//Cabecera: void listar_horarios(int id_prof)
//Precondición: Id_prof ya inicializado.
//Postcondición: Se listan los horarios del profesor seleccionado.
void listar_horarios(char id_prof[]){
    int i;
    id_prof[3]='\n';
    espacios_desc(id_prof);
     for(i=0;i<configuration.horarios_counter;i++){
            if(strcmp(id_prof,horario[i].id_profesor)==0){
                printf("%s-",horario[i].id_profesor); // Escribe el identificador
                printf("%i-",horario[i].dia_clase); // Escribe el dia de clase
                printf("%i-",horario[i].hora_clase); // Escribe la hora de clase
                printf("%s-",horario[i].id_materia);    //Escribe el id de materia
                printf("%s\n",horario[i].grupo);        //Escribe el grupo
            }
        }
}

//Cabecera: espacios_desc(char aux[])
//Precondición: aux inicializado.
//Postcondición: Se modifica el contenido de la cadena para eliminar los saltos de linea.
void espacios_desc(char aux[]){
    int i;
      for(i=0;i<50;i++){
            if(aux[i]=='\n'){
                aux[i]='\0';
            }
        }
}
