#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double rematrix_volume;
extern double *matrix_param;
extern int stride;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    for (j = 0; j < 32; j++) {
        matrix_param[stride * i + j] *= rematrix_volume;
    }
    for (j = 32; j < 64; j++) {
        matrix_param[stride * i + j] *= rematrix_volume;
    }
}
}
