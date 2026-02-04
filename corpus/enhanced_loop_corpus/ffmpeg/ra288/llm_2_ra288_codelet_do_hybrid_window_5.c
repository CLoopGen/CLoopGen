#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern float *out;
extern float *out2;
extern int i;
extern float buffer1[37];
extern float buffer2[37];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Accesses even indices first, then odd if needed, improving potential vectorization or cache behavior
    int limit = order - (order % 2);
    for (i = 0; i <= limit; i += 2) {
        out2[i] = out2[i] * 0.5625 + buffer1[i];
        out[i] = out2[i] + buffer2[i];
        if (i + 1 <= order) {
            out2[i+1] = out2[i+1] * 0.5625 + buffer1[i+1];
            out[i+1] = out2[i+1] + buffer2[i+1];
        }
    }
}
