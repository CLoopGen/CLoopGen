#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 1; i < 32000; i++) {
        if (b[i] != (real_t)0.) {
            a[i] += b[i] * c[i-1]; // Introduce loop-carried dependence via c[i-1]
        }
    }
    // Handle first element separately to avoid out-of-bounds
    if (b[0] != (real_t)0.) {
        a[0] += b[0] * c[31999]; // Create artificial dependency using last element
    }
}
}
