#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct AMRFixed {
    int n;
    int x[10];
    float y[10];
    int no_repeat_mask;
    int pitch_lag;
    float pitch_fac;
} AMRFixed;

AMRFixed *fixed_sparse;
int16_t *pulses;
int i;

void init_vars() {
    // Allocate fixed_sparse as a single struct on heap
    fixed_sparse = (AMRFixed*)calloc(1, sizeof(AMRFixed));
    
    // Initialize struct fields to reasonable defaults
    fixed_sparse->n = 0;
    for (int j = 0; j < 10; j++) {
        fixed_sparse->x[j] = 0;
        fixed_sparse->y[j] = 1.0f;
    }
    fixed_sparse->no_repeat_mask = 0;
    fixed_sparse->pitch_lag = 0;
    fixed_sparse->pitch_fac = 0.0f;

    // Allocate pulses array: we need at least 3 elements for the loop,
    // but make it large enough to meet data size requirement (~1MB)
    // Each int16_t is 2 bytes, so for ~1MB we need about 500,000 elements
    const size_t pulses_size = 500000;
    pulses = (int16_t*)malloc(pulses_size * sizeof(int16_t));
    
    // Seed random number generator for realistic input
    srand((unsigned int)time(NULL));
    
    // Initialize pulses with pseudo-random data in valid range
    // pulses[i] should have meaningful bits in lower 9 bits (used: >>4 &15, &15, &256)
    for (size_t j = 0; j < pulses_size; j++) {
        pulses[j] = (int16_t)(rand() & 511); // 0-511 covers bits used in logic
    }
}