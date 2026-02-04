#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *byte_abs;
int *diff;
int i;
int sad;

void init_vars() {
    const size_t DATA_SIZE = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime on modern CPU
    const int LOOP_BOUND = 64;

    // Allocate and initialize diff array with valid indices within byte_abs bounds
    diff = (int*)malloc(LOOP_BOUND * sizeof(int));
    byte_abs = (int*)malloc(DATA_SIZE * sizeof(int));

    // Initialize byte_abs with random positive values (abs of bytes)
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        byte_abs[idx] = rand() & 0xFF;
    }

    // Initialize diff with random indices in [0, DATA_SIZE - 1]
    for (int idx = 0; idx < LOOP_BOUND; ++idx) {
        diff[idx] = rand() % DATA_SIZE;
    }

    // Initialize scalar variables
    i = 0;
    sad = 0;

    // Seed rand for potential reproducibility if needed (optional, but helps consistency)
    srand((unsigned int)time(NULL));
}