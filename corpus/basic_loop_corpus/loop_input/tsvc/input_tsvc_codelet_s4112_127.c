#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int *restrict ip;
real_t s;

void init_vars() {
    // Initialize scalar
    s = 1.5f;

    // Allocate and initialize index permutation array ip
    ip = (int*)malloc(32000 * sizeof(int));
    if (!ip) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Seed random number generator for index initialization
    srand(time(NULL));

    // Initialize ip[i] to valid indices in [0, 31999] to ensure b[ip[i]] is in bounds
    for (int i = 0; i < 32000; i++) {
        ip[i] = rand() % 32000;
    }

    // Initialize arrays a and b with non-zero values for meaningful computation
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i % 100) * 0.1f;
        b[i] = (real_t)((i + 10) % 100) * 0.2f;
    }
}