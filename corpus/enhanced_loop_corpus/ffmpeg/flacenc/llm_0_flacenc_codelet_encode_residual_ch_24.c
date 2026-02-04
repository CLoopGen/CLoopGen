#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int opt_order;
extern int allsteps;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < opt_order; j++) {
        for (i = 0; i < 3; i++)
            allsteps *= 3;
    }
}
