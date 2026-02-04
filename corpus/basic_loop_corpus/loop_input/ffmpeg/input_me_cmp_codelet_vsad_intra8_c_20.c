#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *s;
ptrdiff_t stride;
int h;
int score;
int x;
int y;

static uint8_t *buffer;
static int buffer_size;

void init_vars() {
    // Set parameters to control data size and loop iterations
    stride = 64;  // Typical cache line aligned stride
    h = 2000;     // Height dimension

    // Total data size: ensure we have at least (h-1)*stride + 12 bytes accessible from s
    // We allocate enough memory to cover the maximum access: s[x + 3 + stride] with x=4, y up to h-1
    buffer_size = (h - 1) * stride + 16;
    buffer = (uint8_t*)aligned_alloc(64, buffer_size);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffer with random but deterministic data
    srand(0);
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = rand() % 256;
    }

    // Initialize s to point to the beginning of buffer
    s = buffer;

    // Initialize other variables
    score = 0;
    x = 0;
    y = 0;
}