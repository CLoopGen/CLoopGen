#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        // Eliminate loop-carried dependency by unrolling and breaking RAW dependency
        // Introduce temporary variables to allow independent computation
        real_t temp_a[256];
        temp_a[0] = a[0]; // Preserve initial value
        for (int j = 1; j < 256; j++) {
            temp_a[j] = (real_t)1. - temp_a[j - 1]; // Still has intra-loop RAW, but now in private storage
        }
        // Update global `a` only after full computation to break WAW across iterations
        for (int j = 1; j < 256; j++) {
            a[j] = temp_a[j];
            aa[j][i] = a[j] + bb[j][i] * d[j];
        }
    }
}
}
