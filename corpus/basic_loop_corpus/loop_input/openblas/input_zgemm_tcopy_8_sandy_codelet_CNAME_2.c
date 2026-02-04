#include <stdio.h>

typedef long BLASLONG;

BLASLONG row;
BLASLONG col;
BLASLONG i;
BLASLONG ii;
float *src0;
float *dest0;

static float *src_buffer;
static float *dest_buffer;
static BLASLONG buffer_size;

void init_vars() {
    // Set problem size to achieve around 0.01 seconds runtime
    // Use ~64MB total data to balance cache effects and timing
    buffer_size = (1 << 23); // ~64M floats = 256MB for both buffers

    // Allocate buffers
    src_buffer = (float*)__builtin_malloc(buffer_size * sizeof(float));
    dest_buffer = (float*)__builtin_malloc(buffer_size * sizeof(float));

    // Initialize matrix-like dimensions
    // We're copying 16 elements per inner block, stepping by 16 in src
    // Each iteration jumps dest by (row << 4) = row*16
    // To avoid out-of-bounds, ensure we don't exceed buffer_size

    // Choose row such that we have reasonable stride
    row = 128;  // stride of 128*16 = 2048 in dest per iteration
    col = 1024; // must be divisible by 8 -> 1024/8 = 128 iterations

    // Ensure total memory access stays within bounds:
    // Total src accessed: 16 * (col/8) = 16 * 128 = 2048
    // Total dest accessed: first element + (col/8 - 1) * row*16 + 16
    //                    = 1 + 127*2048 + 16 = ~260k, well under 64M

    // Initialize pointers to start of buffers
    src0 = src_buffer;
    dest0 = dest_buffer;

    // Initialize source data to prevent undefined behavior
    for (BLASLONG j = 0; j < buffer_size; j++) {
        src_buffer[j] = (float)(j % 1000) / 1000.0f;
    }

    // Zero destination
    for (BLASLONG j = 0; j < buffer_size; j++) {
        dest_buffer[j] = 0.0f;
    }

    // Initialize loop counters
    i = 0;
    ii = 0;
}