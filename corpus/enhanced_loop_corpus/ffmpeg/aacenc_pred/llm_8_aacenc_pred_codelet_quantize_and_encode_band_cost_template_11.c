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
        float sum = 0.0F;
        for (j = 0; j < dim; j++) {
            sum += (float)(j + 1);
            out[i + j] = sum;
        }
    }
}
