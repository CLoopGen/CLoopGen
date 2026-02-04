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
static size_t buffer_size;

void init_vars() {
    // Set parameters to control data size and loop bounds
    stride = 16;          // Stride of 16 bytes
    h = 4096;             // Height: 4096 rows
    score = 0;

    // Total memory needed: h rows, each accessed with stride, plus one extra for s[x + stride + 3]
    buffer_size = (h + 1) * stride + 4;
    buffer = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with random data to avoid optimization away
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < buffer_size; i++) {
        buffer[i] = (uint8_t)(rand() % 256);
    }

    // Assign s to the beginning of the allocated buffer
    s = buffer;
}

// Cleanup function to avoid memory leaks (not called here but good practice)
// Caller must ensure cleanup if needed