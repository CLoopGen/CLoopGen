#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ssize_t i;
unsigned char *p;
unsigned int shift;
unsigned int T;
unsigned int W[64];

static unsigned char data_pool[131072]; // 128KB of input data to ensure ~0.01s runtime

void init_vars() {
    // Initialize shift to a reasonable value (e.g., 12 bits)
    shift = 12;

    // Initialize pointer p to the beginning of our data pool
    p = data_pool;

    // Seed and fill data_pool with pseudo-random data to simulate realistic input
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&data_pool));
    for (size_t idx = 0; idx < sizeof(data_pool); ++idx) {
        data_pool[idx] = (unsigned char)(rand() % 256);
    }

    // Zero-initialize W array to avoid undefined behavior
    memset(W, 0, sizeof(W));

    // Initialize T to zero
    T = 0;
}