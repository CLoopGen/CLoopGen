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
        j = i % dim;
        if (j == 0 || i < dim) {
            out[i] = 0.F;
        } else {
            out[i] = 0.F;
        }
    }
}
