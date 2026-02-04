#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix_param;
extern int stride;
extern int i;
extern int j;
extern double maxcoef;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    int base_index = stride * (i >> 1); // effectively reusing rows
    for (j = 0; j < 32; j++) {
        matrix_param[base_index + j] /= maxcoef;
    }
}
}
