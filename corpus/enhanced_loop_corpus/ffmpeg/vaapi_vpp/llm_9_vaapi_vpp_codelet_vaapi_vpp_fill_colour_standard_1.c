#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_vacs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int x, y;
    for (i = 0; i < nb_vacs / 2; i++) {
        x = i + 1;
        y = nb_vacs - i;
        x *= x + y;
        y -= x / 2;
    }
}
