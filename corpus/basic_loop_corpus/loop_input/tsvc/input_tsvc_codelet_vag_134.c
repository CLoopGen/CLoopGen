#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int *restrict ip;

void init_vars() {
    // Allocate and initialize index permutation array
    ip = (int*)malloc(32000 * sizeof(int));
    
    // Initialize ip[i] to valid indices in range [0, 31999]
    for (int i = 0; i < 32000; i++) {
        ip[i] = i; // identity mapping to ensure valid access
    }
    
    // Initialize b array with sample data
    for (int i = 0; i < 32000; i++) {
        b[i] = (real_t)(i * 2.5);
    }
    
    // Initialize a array if needed
    for (int i = 0; i < 32000; i++) {
        a[i] = 0.0f;
    }
}