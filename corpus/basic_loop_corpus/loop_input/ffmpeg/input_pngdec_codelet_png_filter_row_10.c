#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime estimate

uint8_t *dst;
uint8_t *src;
int size;
int i;
int r;
int g;
int b;
int a;

void init_vars() {
    // Allocate memory for src and dst arrays
    src = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    dst = (uint8_t*)aligned_alloc(32, DATA_SIZE);

    // Initialize the arrays with some sample data
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src[idx] = (uint8_t)(idx % 251); // Prime number to vary values
        dst[idx] = 0;
    }

    // Set size to allow full traversal with step of 3, ensuring i+3 doesn't overflow
    size = DATA_SIZE - 4; // Ensures i+3 is valid when i <= size-3

    // Initialize loop index and accumulator variables
    i = 0;
    r = 1;
    g = 2;
    b = 3;
    a = 4;
}