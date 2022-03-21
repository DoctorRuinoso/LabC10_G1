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

//Restaura configuracion
void core_config_restorer(){

    CONFIGFILE=fopen("config/Configfile.txt","r");
    assert(CONFIG_FILE!=NULL && "No se ha leido correctamente el fichero de config");
    int lineaux;
    for (int i = 0; i < 8; ++i) {//siempre vamos a te ner 3 parametros de configuracion
        fscanf(CONFIG_FILE,"%d",&lineaux);
        if(i==0){
            configuration.usuarios_counter=lineaux;
        }
        else if(i==1){
            configuration.alumnos_counter=lineaux;
        }
        else if(i==2){
            configuration.materias_counter=lineaux;
        }
        else if(i==3){
            configuration.matriculas_counter=lineaux;
        }
        else if(i==4){
            configuration.calificaciones_counter=lineaux;
        }
        else if(i==5){
            configuration.horarios_counter=lineaux;
        }
        
    }
    fclose(CONFIG_FILE);

};//ok

//Finaliza la ejecucion de una funcion
void core_end_execution(){exit(0);}

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

void core_usuarios_update(){
    //Escritura en el fichero
    USUARIOS_FILE = fopen("data/Usuarios.txt","w");
    assert(USUARIOS_FILE!=NULL);
    for (int i = 0; i <configuration.usuarios_counter ; ++i) {
        fprintf(USUARIOS_FILE,"%s",usuario[i].id);
        fprintf(USUARIOS_FILE,"%c",'\n');
        fprintf(USUARIOS_FILE,"%s",usuario[i].nombre);
        fprintf(USUARIOS_FILE,"%c",'\n');
        fprintf(USUARIOS_FILE,"%s",usuario[i].perfil);
        fprintf(USUARIOS_FILE,"%c",'\n');
        fprintf(USUARIOS_FILE,"%s",usuario[i].name_tag);
        fprintf(USUARIOS_FILE,"%c",'\n');
        fprintf(USUARIOS_FILE,"%s",usuario[i].password);
        fprintf(USUARIOS_FILE,"%c",'\n');
    }
    fclose(USUARIOS_FILE);
    core_usuarios_recovery();
}

void core_alumnos_update(){
    //Escritura en el fichero
    ALUMNOS_FILE = fopen("data/Alumnos.txt","w");
    assert(ALUMNOS_FILE!=NULL);
    for (int i = 0; i <configuration.alumnos_counter ; ++i) {
        fprintf(ALUMNOS_FILE,"%s",alumno[i].id);
        fprintf(ALUMNOS_FILE,"%c",'\n');
        fprintf(ALUMNOS_FILE,"%s",alumno[i].nombre);
        fprintf(ALUMNOS_FILE,"%c",'\n');
        fprintf(ALUMNOS_FILE,"%s",alumno[i].direc);
        fprintf(ALUMNOS_FILE,"%c",'\n');
        fprintf(ALUMNOS_FILE,"%s",alumno[i].local);
        fprintf(ALUMNOS_FILE,"%c",'\n');
        fprintf(ALUMNOS_FILE,"%s",alumno[i].curso);
        fprintf(ALUMNOS_FILE,"%c",'\n');
        fprintf(ALUMNOS_FILE,"%s",alumno[i].grupo);
        fprintf(ALUMNOS_FILE,"%c",'\n');
    }
    fclose(ALUMNOS_FILE);
    core_alumnos_recovery();
}


void core_materias_update(){
    //Escritura en el fichero
    MATERIAS_FILE = fopen("data/Materias.txt","w");
    assert(MATERIAS_FILE!=NULL);
    for (int i = 0; i <configuration.materias_counter ; ++i) {
        fprintf(MATERIAS_FILE,"%s",materia[i].id);
        fprintf(MATERIAS_FILE,"%c",'\n');
        fprintf(MATERIAS_FILE,"%s",materia[i].nombre);
        fprintf(MATERIAS_FILE,"%c",'\n');
        fprintf(MATERIAS_FILE,"%s",materia[i].abrev);
        fprintf(MATERIAS_FILE,"%c",'\n');
    }
    fclose(MATERIAS_FILE);
    core_materias_recovery();
}

void core_matriculas_update(){
    //Escritura en el fichero
    MATRICULAS_FILE = fopen("data/Matriculas.txt","w");
    assert(MATRICULAS_FILE!=NULL);
    for (int i = 0; i <configuration.matriculas_counter ; ++i) {
        fprintf(MATRICULAS_FILE,"%s",matricula[i].materia);
        fprintf(MATRICULAS_FILE,"%c",'\n');
        fprintf(MATRICULAS_FILE,"%s",matricula[i].alum);
        fprintf(MATRICULAS_FILE,"%c",'\n');
    }
    fclose(MATRICULAS_FILE);
    core_matriculas_recovery();
}

void core_calificaciones_update(){
    //Escritura en el fichero
    CALIFICACIONES_FILE = fopen("data/Calificaciones.txt","w");
    assert(CALIFICACIONES_FILE!=NULL);
    for (int i = 0; i <configuration.calificaciones_counter ; ++i) {
        fprintf(CALIFICACIONES_FILE,"%s",nota[i].fecha);
        fprintf(CALIFICACIONES_FILE,"%c",'\n');
        fprintf(CALIFICACIONES_FILE,"%s",nota[i].descrip);
        fprintf(CALIFICACIONES_FILE,"%c",'\n');
        fprintf(CALIFICACIONES_FILE,"%s",nota[i].id_materia);
        fprintf(CALIFICACIONES_FILE,"%c",'\n');
        fprintf(CALIFICACIONES_FILE,"%s",nota[i].id_alum);
        fprintf(CALIFICACIONES_FILE,"%c",'\n');
        fprintf(CALIFICACIONES_FILE,"%s",nota[i].valor);
        fprintf(CALIFICACIONES_FILE,"%c",'\n');
    }
    fclose(CALIFICACIONES_FILE);
    core_calificaciones_recovery();
}

void core_horarios_update(){
    //Escritura en el fichero
    CALIFICACIONES_FILE = fopen("data/Horarios.txt","w");
    assert(HORARIOS_FILE!=NULL);
    for (int i = 0; i <configuration.horarios_counter ; ++i) {
        fprintf(HORARIOS_FILE,"%s",horario[i].id_profesor);
        fprintf(HORARIOS_FILE,"%c",'\n');
        fprintf(HORARIOS_FILE,"%s",horario[i].dia_clase);
        fprintf(HORARIOS_FILE,"%c",'\n');
        fprintf(HORARIOS_FILE,"%s",horario[i].hora_clase);
        fprintf(HORARIOS_FILE,"%c",'\n');
        fprintf(HORARIOS_FILE,"%s",horario[i].id_materia);
        fprintf(HORARIOS_FILE,"%c",'\n');
        fprintf(HORARIOS_FILE,"%s",horario[i].grupo);
        fprintf(HORARIOS_FILE,"%c",'\n');
    }
    fclose(HORARIOS_FILE);
    core_horarios_recovery();
}
