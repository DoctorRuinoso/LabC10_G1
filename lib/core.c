#include "core.h"
//
//Llama a los restauradores de cada struct (fisica -> RAM)
void Core_data_recovery(){
    Core_config_restorer();
    Core_usuarios_recovery();
    Core_alumnos_recovery();
    Core_matriculas_recovery();
    Core_materias_recovery();
    Core_calificaciones_recovery();
    Core_horarios_recovery();
}

//Recupera las instancias de los usuarios
void Core_usuarios_recovery(){

    assert(configuration.usuarios_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    USERFILE=fopen("data/usuarios.txt", "r");
    jugadores = malloc(sizeof(usuario)*configuration.usuarios_counter);
    for (int i = 0; i < configuration.usuarios_counter; ++i) {
        fscanf(USERFILE,"%s",usuario[i].id);
        fscanf(USERFILE,"%s",usuario[i].nombre);
        fscanf(USERFILE,"%s",usuario[i].perfil);
        fscanf(USERFILE,"%s",&usuario[i].name_tag);
        fscanf(USERFILE,"%s",&usuairo[i].password);
    }

    fclose(USERFILE);