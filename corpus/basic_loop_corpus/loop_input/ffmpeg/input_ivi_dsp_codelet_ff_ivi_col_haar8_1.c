#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *in;
int16_t *out;
ptrdiff_t pitch;
uint8_t *flags;
int i;
int t0;
int t1;
int t2;
int t3;
int t4;
int t5;
int t6;
int t7;
int t8;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB to ensure sufficient runtime (~0.01s estimate)
#define NUM_ITERATIONS 8

static int32_t in_buffer[DATA_SIZE + 64];  // Add padding for safe access up to in[56]
static int16_t out_buffer[DATA_SIZE * 8];  // Each input produces 8 outputs
static uint8_t flags_buffer[NUM_ITERATIONS];

void init_vars() {
    // Initialize scalar variables
    i = 0;
    t0 = t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = 0;
    pitch = 1;  // Default stride for output

    // Seed random data for variability and realistic execution
    srand((unsigned int)time(NULL));

    // Initialize input buffer with random values
    for (size_t idx = 0; idx < DATA_SIZE + 64; idx++) {
        in_buffer[idx] = (rand() % 2000) - 1000;  // Small integers to avoid overflow
    }

    // Initialize flags: alternate true/false to exercise both branches
    for (int idx = 0; idx < NUM_ITERATIONS; idx++) {
        flags_buffer[idx] = (idx % 2);  // Alternates 0,1
    }

    // Initialize output buffer to zero
    memset(out_buffer, 0, sizeof(out_buffer));

    // Assign external pointers to point into buffers
    in = in_buffer;
    out = out_buffer;
    flags = flags_buffer;
}