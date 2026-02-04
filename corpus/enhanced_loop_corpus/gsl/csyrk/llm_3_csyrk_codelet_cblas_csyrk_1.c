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
    // Variant 2: Strided memory access - traverse column-major like pattern with fixed stride in j-loop
    float *C_base = (float *)C;
    for (j = 0; j < N; j++) {
        for (i = j; i < N; i++) {  // Reverse dependency: ensure i >= j
            int offset = 2 * (ldc * i + j);
            C_base[offset]     = 0.;
            C_base[offset + 1] = 0.;
        }
    }
}
