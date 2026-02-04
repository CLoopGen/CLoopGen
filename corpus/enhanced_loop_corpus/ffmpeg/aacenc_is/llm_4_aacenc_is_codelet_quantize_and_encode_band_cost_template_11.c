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
        int limit = (i + dim <= size) ? dim : size - i;
        for (j = 0; j < limit; j++) {
            if ((i + j) >= 0 && (i + j) < size) {
                out[i + j] = 0.F;
            }
        }
    }
}
