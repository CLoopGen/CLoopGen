#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *wf;
extern float vals[8];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize access to wf to be consecutive by precomputing base indices and accessing in a linear fashion
    for (i = 0; i < 4; i++) {
        float sum = 0.F;
        const int base_idx = 8 + i;
        for (j = 0; j < 4; j++) {
            int idx = base_idx + (j << 2); // Equivalent to 8 + i + j*4
            sum += vals[j] * wf[idx];
        }
        vals[4 + i] = sum + wf[24 + i]; // 8 + 16 + i = 24 + i
    }
}
