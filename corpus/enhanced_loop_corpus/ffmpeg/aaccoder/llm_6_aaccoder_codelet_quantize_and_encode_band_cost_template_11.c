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
    float temp = 0.F;
    for (i = 0; i < size; i += dim) {
        temp += 1.F; // Introduce loop-carried dependency via temp
        for (j = 0; j < dim; j++) {
            out[i + j] = temp; // WAW and RAW dependencies introduced: each write depends on previous iteration's temp
        }
    }
}
