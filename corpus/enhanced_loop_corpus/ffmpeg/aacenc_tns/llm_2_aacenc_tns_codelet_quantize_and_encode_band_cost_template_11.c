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
    // Variant 1: Consecutive memory access by reordering loops to ensure sequential writes
    for (j = 0; j < dim; j++) {
        for (i = 0; i < size; i += dim) {
            out[i + j] = 0.F;
        }
    }
}
