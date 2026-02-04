#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int *restrict ip;
real_t sum;

void init_vars() {
    // Initialize arrays a and b with some non-zero values for computation
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + (i * 0.0001f);
        b[i] = 0.5f + ((32000 - i) * 0.0001f);
    }

    // Allocate and initialize index permutation array ip
    // Ensure all indices are within valid range [0, 31999]
    ip = (int*)malloc(32000 * sizeof(int));
    if (!ip) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Simple sequential initialization with wrap-around to stay in bounds
    for (int i = 0; i < 32000; i++) {
        ip[i] = (i * 17) % 32000;  // Linear congruential pattern to avoid cache correlation
    }

    // Initialize sum to zero
    sum = 0.0;
}