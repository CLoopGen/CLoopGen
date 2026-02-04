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
    for (i = 0; i < size; i++) {
        out[i] = 0.F;
        if (i % dim == 0 && i + dim - 1 < size) {
            for (j = 1; j < dim; j++) {
                out[i + j] = out[i] + (float)j;
            }
            i += dim - 1;
        }
    }
}
