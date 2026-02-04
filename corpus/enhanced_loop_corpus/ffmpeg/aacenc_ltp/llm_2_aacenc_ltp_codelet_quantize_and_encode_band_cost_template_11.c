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
    // Variant 1: Strided memory access pattern
    // Instead of accessing consecutive blocks of size 'dim', we now write to every 'dim'-th element first,
    // creating a strided access pattern across the output array.
    for (j = 0; j < dim; j++)
        for (i = 0; i < size; i += dim)
            out[i + j] = 0.F;
}
