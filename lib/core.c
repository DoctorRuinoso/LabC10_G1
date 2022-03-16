#include "core.h"
//
//Llama a los restauradores de cada struct (fisica -> RAM)
void core_data_recovery(){
    core_config_restorer();
    core_usuarios_recovery();
    core_alumnos_recovery();
    core_matriculas_recovery();
    core_materias_recovery();
    core_calificaciones_recovery();
    core_horarios_recovery();
}

//Recupera las instancias de los usuarios
void core_usuarios_recovery(){

    assert(configuration.usuarios_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    USUARIOS_FILE=fopen("data/usuarios.txt", "r");
    usuario = malloc(sizeof(usuarios)*configuration.usuarios_counter);
    for (int i = 0; i < configuration.usuarios_counter; ++i) {
        fscanf(USUARIOS_FILE,"%s",usuario[i].id);
        fscanf(USUARIOS_FILE,"%s",usuario[i].nombre);
        fscanf(USUARIOS_FILE,"%s",usuario[i].perfil);
        fscanf(USUARIOS_FILE,"%s",usuario[i].name_tag);
        fscanf(USUARIOS_FILE,"%s",usuario[i].password);
    }

    fclose(USUARIOS_FILE);
}

void core_alumnos_recovery(){

    assert(configuration.alumnos_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    ALUMNOS_FILE=fopen("data/alumnos.txt", "r");
    alumno = malloc(sizeof(alumnos)*configuration.alumnos_counter);
    for (int i = 0; i < configuration.alumnos_counter; ++i) {
        fscanf(ALUMNOS_FILE,"%s",alumno[i].id);
        fscanf(ALUMNOS_FILE,"%s",alumno[i].nombre);
        fscanf(ALUMNOS_FILE,"%s",alumno[i].direc);
        fscanf(ALUMNOS_FILE,"%s",alumno[i].local);
        fscanf(ALUMNOS_FILE,"%s",alumno[i].curso);
        fscanf(ALUMNOS_FILE,"%s",alumno[i].grupo);

    fclose(ALUMNOS_FILE);
}

void core_materias_recovery(){

    assert(configuration.materias_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    MATERIAS_FILE=fopen("data/materias.txt", "r");
    materia = malloc(sizeof(materias)*configuration.materias_counter);
    for (int i = 0; i < configuration.materias_counter; ++i) {
        fscanf(MATERIAS_FILE,"%s",materia[i].id);
        fscanf(MATERIAS_FILE,"%s",materia[i].nombre);
        fscanf(MATERIAS_FILE,"%s",materia[i].abrev);

    fclose(MATERIAS_FILE);
}


void core_matriculas_recovery(){

    assert(configuration.matriculas_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    MATRICULAS_FILE=fopen("data/matriculas.txt", "r");
    matricula = malloc(sizeof(matriculas)*configuration.matriculas_counter);
    for (int i = 0; i < configuration.matriculas_counter; ++i) {
        fscanf(MATRICULAS_FILE,"%s",matricula[i].materia);
        fscanf(MATRICULAS_FILE,"%s",matricula[i].alum);

    fclose(MATRICULAS_FILE);
}

void core_calificaciones_recovery(){

    assert(configuration.calificaciones_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    CALIFICACIONES_FILE=fopen("data/calificaciones.txt", "r");
    nota = malloc(sizeof(calificaciones)*configuration.calificaciones_counter);
    for (int i = 0; i < configuration.usuarios_counter; ++i) {
        fscanf(CALIFICACIONES_FILE,"%s",nota[i].fecha);
        fscanf(CALIFICACIONES_FILE,"%s",nota[i].descrip);
        fscanf(CALIFICACIONES_FILE,"%s",nota[i].id_materia);
        fscanf(CALIFICACIONES_FILE,"%s",nota[i].id_alum);
        fscanf(CALIFICACIONES_FILE,"%f",nota[i].valor);
    }

    fclose(CALIFICACIONES_FILE);
}

void core_horarios_recovery(){

    assert(configuration.horarios_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    HORARIOS_FILE=fopen("data/horarios.txt", "r");
    horario = malloc(sizeof(horarios)*configuration.horarios_counter);
    for (int i = 0; i < configuration.horarios_counter; ++i) {
        fscanf(HORARIOS_FILE,"%s",horario[i].id_profesor);
        fscanf(HORARIOS_FILE,"%i",horario[i].dia_clase);
        fscanf(HORARIOS_FILE,"%i",horario[i].hora_clase);
        fscanf(HORARIOS_FILE,"%s",horario[i].id_materia);
        fscanf(HORARIOS_FILE,"%s",horario[i].grupo);
    }

    fclose(HORARIOS_FILE);
}




