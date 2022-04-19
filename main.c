#include <stdio.h>
#include <string.h>
#include "lib/core.h"
#include "lib/profesor.h"
#include "lib/administrador.h"


int main() {

    unsigned exit_token=1;
    unsigned logged_user;
    core_data_recovery();
    while (exit_token==1)
    {
        if (core_config_options_menu()== 1)
            alta_usuario();//fallo
        else{logged_user=core_login();}

        if (strcmp(usuario[logged_user].perfil,"a")==0){
            menu_administrador(logged_user);
        }
        if (strcmp(usuario[logged_user].perfil,"p")==0){
            //perfil_profesor_menu_general(logged_user);
        }
        printf("Deseas hacer alguna operacion mas?\n1)Si\t 2)No\n");
        scanf("%d",&exit_token);

    }
    core_end_execution();

    return 0;
}