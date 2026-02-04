#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_surfaces;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nb_surfaces && i < 1000; i++) {
        if (i == 500) {
            break;
        }
    }
}
