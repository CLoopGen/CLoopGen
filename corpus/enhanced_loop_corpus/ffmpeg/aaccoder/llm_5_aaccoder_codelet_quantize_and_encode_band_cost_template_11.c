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
    for (i = 0; i < size && dim > 0; i += dim) {
        for (j = 0; j < dim && (i + j) < size; j++) {
            out[i + j] = 0.F;
        }
    }
}
