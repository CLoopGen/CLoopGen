#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse column-major within the upper triangle
    // Instead of row-wise, we iterate by fixed stride across rows for each column
    double *c_base = (double *)C;
    int offset;
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {  // Upper triangle accessed via column-dominant order
            offset = 2 * (ldc * i + j);
            c_base[offset]     = 0.0;
            c_base[offset + 1] = 0.0;
        }
    }
}
