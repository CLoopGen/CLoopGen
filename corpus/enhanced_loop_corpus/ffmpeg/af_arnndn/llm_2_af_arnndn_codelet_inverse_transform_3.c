#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern  AVComplexFloat *in;
extern AVComplexFloat x[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    int n = (120 << 2) + 1;
    int i;
    for (i = 0; i < n - 1; i += 2) {
        x[i]     = in[i];
        x[i + 1] = in[i + 1];
    }
    if (i < n) {
        x[i] = in[i];
    }
}
