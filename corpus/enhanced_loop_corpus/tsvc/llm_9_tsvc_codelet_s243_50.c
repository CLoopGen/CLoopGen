#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 16000; i++) {
        // Reduced data range, higher trip count, lower arithmetic per iteration
        a[i] = b[i] + c[i] * d[i];
        b[i] = a[i] + d[i] * e[i];
    }
    // Second smaller loop to maintain dependency structure
    for (int i = 0; i < 16000; i++) {
        a[i] = b[i] + a[i + 1] * d[i];
    }
}
}
