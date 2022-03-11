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

    int defaultBugdet;
    unsigned usuarios_counter;
    unsigned alumnos_counter;
    unsigned materias_counter;
    unsigned matriculas_counter;
    unsigned calificaciones_counter;
    unsigned horarios_counter;

}config_log;

typedef struct{
    char id[3];
    char nombre[20];
    char perfil[1];  //a-> administrador, p-> profesor
    char name_tag[5];
    char password[8];

}usuario;

typedef struct{
    char id[6];
    char nombre[20];
    char direc[30];
    char local[5];
    char curso[30];
    char grupo[10];	
}alumno;

typedef struct{
    char id[4];
    char nombre[50];
    char abrev[3];	
}materia;

typedef struct{
    char id_materia[4];
    char id_alum[6];
}matricula;

typedef struct{
    char fecha[10];
    char descrip[30];
    char id_materia[4];
    char id_alum[6];
    float valor;	
}calificaciones;

typedef struct{
    char id_profesor[3];
    int dia_clase;
    int hora_clase[4];
    char id_materia[4];
    char grupo[10]; 		
}horario;




#endif //MP2022_CORE_H