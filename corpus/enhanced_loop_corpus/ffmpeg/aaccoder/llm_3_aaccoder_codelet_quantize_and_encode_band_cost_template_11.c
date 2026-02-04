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
    // Variant 2: Strided memory access
    // Instead of writing contiguous blocks of 'dim' elements, we write every 'dim'-th element
    // first, then proceed to the next offset. This changes access from row-major block style
    // to column-major or strided style, effectively transposing the access pattern.
    for (j = 0; j < dim; j++)
        for (i = 0; i < size; i += dim)
            out[i + j] = 0.F;
}
