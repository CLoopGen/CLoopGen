#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef struct AMRFixed {
    int n;
    int x[10];
    float y[10];
    int no_repeat_mask;
    int pitch_lag;
    float pitch_fac;
} AMRFixed;

float *out;
AMRFixed *in;
int size;
int i;

#define DATA_SIZE (64 << 20) // ~64MB of data for sufficient runtime (~0.01 sec)

void init_vars() {
    // Allocate output array
    out = (float*)calloc(DATA_SIZE, sizeof(float));
    if (!out) {
        exit(1);
    }

    // Allocate input structure
    in = (AMRFixed*)malloc(sizeof(AMRFixed));
    if (!in) {
        exit(1);
    }

    // Initialize in fields
    in->n = 10; // Fixed by struct definition (x[10])
    in->no_repeat_mask = 0x3FF; // 10 bits set (for 10 elements)
    in->pitch_lag = 1024; // Ensure reasonable step size
    in->pitch_fac = 0.75f;

    // Initialize x indices to valid positions within [0, size)
    // Spread starting points across the first few thousand to trigger multiple iterations
    for (int j = 0; j < 10; j++) {
        in->x[j] = j * 500; // Starting offsets
    }

    // Set global size to match allocated output buffer
    size = DATA_SIZE;

    // Ensure no memory access goes out of bounds:
    // The loop does: x += pitch_lag while x < size and condition holds
    // With pitch_lag=1024 and size=64MB, this is safe as long as initial x[i] < size
}