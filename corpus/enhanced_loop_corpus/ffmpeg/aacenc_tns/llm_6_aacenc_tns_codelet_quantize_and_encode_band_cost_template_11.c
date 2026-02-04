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
        for (j = 0; j < dim; j++) {
            temp = out[i + j];       // Introduce RAW dependency: read before write in next iteration
            out[i + j] = temp;       // WAW and WAR dependencies introduced via temp
        }
    }
}
