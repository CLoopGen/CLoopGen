#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;
extern int j;
extern  int dim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i += dim) {
        float temp = 0.F;
        for (j = 0; j < dim; j++) {
            temp += out[i + j]; // Introduce RAW dependency: each read of out[i+j] feeds into temp
            out[i + j] = temp; // Introduce WAW and WAR dependencies: write affects next iteration via temp
        }
    }
}
