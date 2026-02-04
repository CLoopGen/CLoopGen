#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
int *restrict ip;

void init_vars() {
    // Allocate and initialize index permutation array
    ip = (int*)aligned_alloc(64, 32000 * sizeof(int));
    
    // Initialize arrays with meaningful data to avoid zero or constant folding
    for (int i = 0; i < 32000; i++) {
        b[i] = 1.0f + i * 0.0001f;
        c[i] = 2.0f + i * 0.0002f;
        d[i] = 3.0f + i * 0.0003f;
        // Ensure indices are within bounds [0, 31999]
        ip[i] = (i * 17) % 32000;  // Linear congruential permutation
    }
}