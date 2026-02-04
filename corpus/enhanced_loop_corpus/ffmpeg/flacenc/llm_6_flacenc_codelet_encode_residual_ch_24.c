#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int opt_order;
extern int allsteps;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 1;
    for (i = 0; i < opt_order; i++) {
        temp *= 3;
    }
    allsteps = temp;
}
