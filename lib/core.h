/*
 * Contiene el manejo de las herramientas del sistema y el manejo de los archivos de configuracion
 *
 * */

#ifndef MP2022_CORE_H
#define MP2022_CORE_H
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//Structs

typedef struct {

    unsigned usuarios_counter;
    unsigned alumnos_counter;
    unsigned materias_counter;
    unsigned matriculas_counter;
    unsigned calificaciones_counter;
    unsigned horarios_counter;

}config_log;

typedef struct{
    char id; //Al pedir dato restringir a 3 dígitos//
    char nombre[20];
    char perfil[1];  //a-> administrador, p-> profesor
    char name_tag[5];
    char password[8];

}usuarios;

typedef struct{
    int id; //Al pedir dato restringir a 6 dígitos//
    char nombre[20];
    char direc[30];
    char local[5];
    char curso[30];
    char grupo[10];	
}alumnos;

typedef struct{
    int id; //Al pedir dato restringir a 4 dígitos//
    char nombre[50];
    char abrev[3];	
}materias;

typedef struct{
    int id_materia; //Al pedir dato restringir a 4 dígitos//
    int id_alum; //Al pedir dato restringir a 6 dígitos//
}matriculas;

typedef struct{
    char fecha[10];
    char descrip[30];
    int id_materia; //Al pedir dato restringir a 4 dígitos//
    int id_alum; //Al pedir dato restringir a 6 dígitos//
    float valor;	
}calificaciones;

typedef struct{
    int id_profesor; //Al pedir dato restringir a 3 dígitos//
    int dia_clase;
    int hora_clase[4];
    int id_materia; //Al pedir dato restringir a 4  dígitos//
    char grupo[10]; 		
}horarios;

//Globales de confg

FILE *CONFIG_FILE;
FILE *USUARIOS_FILE;
FILE *ALUMNOS_FILE;
FILE *MATERIAS_FILE;
FILE *MATRICULAS_FILE;
FILE *CALIFICACIONES_FILE;
FILE *HORARIOS_FILE;

//STRUCTS

config_log *configuration;
usuarios *usuario;
alumnos *alumno;
materias *materia;
matriculas *matricula;
calificaciones *nota;
horarios *horario;


//Cabeceras de Funcion

void core_config_restorer();    //Cabecera: void core_config_restorer();
                                //Precondición: tipo de estructura config_log inicializada.
                                //Postcondición: restaura configuración de las demás estructuras.


void core_end_execution();      //Cabecera: void core_end_execution();
                                //Precondición: ninguna.
                                //Postcondición: función para salir del sistema.


void core_config_changer();     //Cabecera: void core_config_changer();
                                //Precondición: tipo de estructura config_log inicializada.
                                //Postcondición: guarda en el fichero configfile.txt los datos del
                                // tipo de estructuta config_log.


void core_data_recovery();      //Cabecera: void core_data_recovery();
                                //Precondición: tener definidas las funciones a las que llama.
                                //Postcondición: llama a todas las funciones recovery a la vez.



void core_config_options_menu();    //Cabecera: void core_config_options_menu();
                                    //Precondición:
                                    //Postcondición:



void core_usuarios_recovery();      //Cabecera: void core_usuarios_recovery();
                                    //Precondición: fichero usuarios.txt creado y el tipo de estructura  usuarios inicializada.
                                    //Postcondición: copia los datos del fichero a la estructura.

void core_alumnos_recovery();       //Cabecera: void core_alumnos_recovery();
                                    //Precondición: fichero alumnos.txt creado y el tipo de estructura  alumnos inicializada,
                                    //Postcondición: copia los datos del fichero a la estructura.

void core_materias_recovery();      //Cabecera: void core_materias_recovery();
                                    //Precondición: fichero materias.txt creado y el tipo de estructura  materias inicializada,
                                    //Postcondición: copia los datos del fichero a la estructura.


void core_matriculas_recovery();    //Cabecera: void core_matriculas_recovery();
                                    //Precondición: fichero matriculas.txt creado y el tipo de estructura  matriculas inicializada,
                                    //Postcondición: copia los datos del fichero a la estructura.

void core_calificaciones_recovery();    //Cabecera: void core_calificaciones_recovery();
                                        //Precondición: fichero calificaciones.txt creado y el tipo de estructura calificaciones inicializada,
                                        //Postcondición: copia los datos del fichero a la estructura.

void core_horarios_recovery();      //Cabecera: void core_horarios_recovery();
                                    //Precondición: fichero horarios.txt creado y el tipo de estructura horarios inicializada,
                                    //Postcondición: copia los datos del fichero a la estructura.

void core_usuarios_update();        //Cabecera: void core_usuarios_update();
                                    //Precondición: fichero usuarios.txt creado y el tipo de estructura usuarios inicializada,
                                    //Postcondición: copia los datos de la estructura al fichero.


void core_alumnos_recovery();       //Cabecera: void core_alumnos_recovery();
                                    //Precondición: fichero alumnos.txt creado y el tipo de estructura  alumnos inicializada,
                                    //Postcondición: copia los datos del fichero a la estructura.

void core_materias_update();        //Cabecera: void core_materias_recovery();
                                    //Precondición: fichero materias.txt creado y el tipo de estructura  materias inicializada,
                                    //Postcondición: copia los datos de la estructura al fichero.


void core_matriculas_update();      //Cabecera: void core_matriculas_recovery();
                                    //Precondición: fichero matriculas.txt creado y el tipo de estructura  matriculas inicializada,
                                    //Postcondición: copia los datos de la estructura al fichero.

void core_calificaciones_update();      //Cabecera: void core_calificaciones_recovery();
                                        //Precondición: fichero calificaciones.txt creado y el tipo de estructura calificaciones inicializada,
                                        //Postcondición: copia los datos de la estructura al fichero.

void core_horarios_update();        //Cabecera: void core_horarios_recovery();
                                    //Precondición: fichero horarios.txt creado y el tipo de estructura horarios inicializada,
                                    //Postcondición: copia los datos de la estructura al fichero.

void alta_usuario();
void core_login();

//Crear Una funcion que contabilice el vacio de las eliminadas




#endif //MP2022_CORE_H