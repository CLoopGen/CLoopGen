#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *restrict block;
uint8_t *s1;
uint8_t *s2;
ptrdiff_t stride;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure loop runtime around 0.01s

static int16_t block_data[DATA_SIZE / sizeof(int16_t)];
static uint8_t s1_data[DATA_SIZE];
static uint8_t s2_data[DATA_SIZE];

void init_vars() {
    stride = 16; // reasonable stride for memory access pattern

    // Initialize pointers to point into the allocated arrays
    // Ensure that during all loop iterations, we don't go out of bounds
    // Loop runs 8 times, each time accessing 8 elements -> need 64 elements per dimension
    // And we advance by stride each time -> total required: 8*stride bytes in each buffer

    s1 = s1_data;
    s2 = s2_data;
    block = block_data;

    // Initialize input data to avoid undefined behavior
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        s1_data[idx] = rand() % 256;
        s2_data[idx] = rand() % 256;
    }

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(int16_t); idx++) {
        block_data[idx] = 0;
    }
}