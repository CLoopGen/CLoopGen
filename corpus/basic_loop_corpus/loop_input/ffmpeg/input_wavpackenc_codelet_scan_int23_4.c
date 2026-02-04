#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *samples_l;
int nb_samples;
uint32_t magdata;
uint32_t ordata;
uint32_t xordata;
uint32_t anddata;
int i;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~256MB of int32_t data
    nb_samples = input_size / sizeof(int32_t);
    samples_l = (int32_t*)aligned_alloc(32, input_size);
    
    if (!samples_l) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Seed random generator for realistic data
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&nb_samples));

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = rand() ^ (rand() << 16);
    }

    // Initialize accumulators
    magdata = 0;
    ordata = 0;
    xordata = 0;
    anddata = 0xFFFFFFFF; // Start with all bits set for proper AND reduction
    i = 0;
}