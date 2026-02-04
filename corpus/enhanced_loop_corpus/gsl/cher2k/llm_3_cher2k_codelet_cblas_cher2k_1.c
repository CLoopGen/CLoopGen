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
    // Variant 2: Strided memory access with transposed traversal order (column-major like)
    float *C_base = (float *)C;
    for (j = 0; j < N; j++) {
        for (i = j; i < N; i++) {
            int index = 2 * (ldc * i + j);
            C_base[index] = 0.;
            C_base[index + 1] = 0.;
        }
    }
}
