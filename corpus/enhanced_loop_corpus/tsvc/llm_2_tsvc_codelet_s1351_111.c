#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    real_t *restrict A = a;
    real_t *restrict B = b;
    real_t *restrict C = c;
    for (int i = 0; i < 32000; i += 4) {
        A[i] = B[i] + C[i];
        A[i+1] = B[i+1] + C[i+1];
        A[i+2] = B[i+2] + C[i+2];
        A[i+3] = B[i+3] + C[i+3];
    }
}
}
