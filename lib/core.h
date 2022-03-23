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

void core_config_restorer();
void core_end_execution();
void core_config_changer();
void core_data_recovery();
void core_usuarios_recovery();
void core_alumnos_recovery();
void core_materias_recovery();
void core_matriculas_recovery();
void core_calificaciones_recovery();
void core_horarios_recovery();
void core_usuarios_update();
void core_alumnos_update();
void core_materias_update();
void core_matriculas_update();
void core_calificaciones_update();
void core_horarios_update();
void alta_usuario()

//Crear Una funcion que contabilice el vacio de las eliminadas




#endif //MP2022_CORE_H