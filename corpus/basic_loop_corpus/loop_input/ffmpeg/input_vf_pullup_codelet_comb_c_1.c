#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB to target ~0.01 sec runtime

uint8_t *a;
uint8_t *b;
ptrdiff_t s;
int i;
int j;
int comb;

static uint8_t buffer_a[DATA_SIZE];
static uint8_t buffer_b[DATA_SIZE];

void init_vars() {
    // Initialize scalar variables
    s = 16; // Stride value that ensures safe access with j+s and j-s within bounds
    i = 0;
    j = 0;
    comb = 0;

    // Initialize pointers to middle of buffers to allow indexing with j-s and j+s
    // Ensure that for j in [0,7]: j-s >= -s and j+s <= 7+s are within buffer bounds
    // We place a and b at offset s from start to allow b[j-s] when j=0
    a = buffer_a + s;
    b = buffer_b + s;

    // Initialize buffer contents to prevent undefined behavior
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        buffer_a[idx] = rand() & 0xFF;
        buffer_b[idx] = rand() & 0xFF;
    }
}