#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dfdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            dfdy[i * 15 + j] = (double)(i + j) * 0.1 - (double)(i * j) * 0.01;
        }
    }
}
