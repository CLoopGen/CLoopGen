#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4 (access every 4th element in groups)
    int stride = 4;
    for (i = 0; i < size; i += 16) {
        if (i + 0 < size) out[i + 0] = 0.F;
        if (i + 4 < size) out[i + 4] = 0.F;
        if (i + 8 < size) out[i + 8] = 0.F;
        if (i + 12 < size) out[i + 12] = 0.F;
        if (i + 1 < size) out[i + 1] = 0.F;
        if (i + 5 < size) out[i + 5] = 0.F;
        if (i + 9 < size) out[i + 9] = 0.F;
        if (i + 13 < size) out[i + 13] = 0.F;
        if (i + 2 < size) out[i + 2] = 0.F;
        if (i + 6 < size) out[i + 6] = 0.F;
        if (i + 10 < size) out[i + 10] = 0.F;
        if (i + 14 < size) out[i + 14] = 0.F;
        if (i + 3 < size) out[i + 3] = 0.F;
        if (i + 7 < size) out[i + 7] = 0.F;
        if (i + 11 < size) out[i + 11] = 0.F;
        if (i + 15 < size) out[i + 15] = 0.F;
    }
}
