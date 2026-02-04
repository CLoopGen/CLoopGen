#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *levels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = -100.;
    for (int i = 0; i < 15; i++) {
        levels[i] = temp;
    }
}
