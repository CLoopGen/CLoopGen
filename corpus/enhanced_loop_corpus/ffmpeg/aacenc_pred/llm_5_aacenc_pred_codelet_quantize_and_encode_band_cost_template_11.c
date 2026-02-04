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
        int upper = (i + dim <= size) ? i + dim : size;
        for (j = 0; j < upper - i; j++) {
            out[i + j] = 0.F;
        }
    }
}
