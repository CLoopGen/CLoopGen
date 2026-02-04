#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB total data
static uint8_t memory_pool[DATA_SIZE];

void init_vars() {
    // Initialize scalar variables
    A = 42; // arbitrary non-zero coefficient
    h = 16384; // number of iterations
    stride = 16; // stride greater than 8 to avoid overlap and simulate 2D stepping

    // Ensure we have enough memory for h * stride access with offset up to 7
    if (h * stride + 8 > DATA_SIZE / 2) {
        // Adjust h to fit within bounds if needed
        h = (DATA_SIZE / 2 - 8) / stride;
    }

    // Assign memory regions
    dst = memory_pool;
    src = memory_pool + (DATA_SIZE / 2);

    // Initialize dst and src data to prevent undefined behavior
    for (int j = 0; j < h * stride + 8; j++) {
        dst[j] = (uint8_t)(j % 256);
        src[j] = (uint8_t)((j * 37) % 256);
    }
}