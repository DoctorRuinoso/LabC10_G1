#include <stdio.h>
#include <string.h>
#include "lib/core.h"

int main() {
    core_config_restorer();


    printf("%i\n",configuration.usuarios_counter);
    
    return 0;
}