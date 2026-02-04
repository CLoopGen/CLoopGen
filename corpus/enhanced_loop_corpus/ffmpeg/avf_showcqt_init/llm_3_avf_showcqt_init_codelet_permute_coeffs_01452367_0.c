#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *v;
extern int len;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    float *base = v;
    for (k = 0; k < len; k += 8) {
        float *pk2 = base + k + 2;
        float *pk3 = base + k + 3;
        float *pk4 = base + k + 4;
        float *pk5 = base + k + 5;

        float tmp4 = *pk4;
        *pk4 = *pk2;
        *pk2 = tmp4;

        float tmp5 = *pk5;
        *pk5 = *pk3;
        *pk3 = tmp5;
    }
}
