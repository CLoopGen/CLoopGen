#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
int *restrict ip;

void init_vars() {
    // Allocate and initialize index permutation array
    ip = (int*)malloc(32000 * sizeof(int));
    
    // Initialize ip[i] to valid indices within [0, 31999]
    for (int i = 0; i < 32000; i++) {
        ip[i] = i; // Identity mapping to ensure valid access
    }
    
    // Initialize arrays with non-zero values to make computation meaningful
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f + i * 0.001f;
        c[i] = 3.0f - i * 0.0005f;
    }
}