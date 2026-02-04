#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int size;
int x;
int y;
uint8_t *src;
int angle;
uint8_t *ref;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)

static uint8_t src_data[DATA_SIZE];
static uint8_t ref_data[DATA_SIZE + 128];  // Extra padding to prevent out-of-bounds access

void init_vars() {
    size = 8192;  // Choose size such that total operations scale appropriately
    while (size * size > DATA_SIZE) {
        size >>= 1;
    }
    stride = size;
    angle = 16;  // Ensures fractional shifts in [0,31] range
    src = src_data;
    ref = ref_data;

    // Ensure memory is initialized and accesses remain in bounds
    // Max idx: ((size - 1 + 1) * angle) >> 5 = (size * angle) >> 5
    int max_idx = (size * angle) >> 5;
    // Max offset into ref: y + idx + 2 <= size - 1 + max_idx + 2
    int required_ref_size = size + max_idx + 2;
    if (required_ref_size > DATA_SIZE + 128) {
        exit(1);  // Should not happen with current parameters
    }

    for (int i = 0; i < DATA_SIZE; i++) {
        src_data[i] = 0;
    }
    for (int i = 0; i < required_ref_size; i++) {
        ref_data[i] = rand() & 0xFF;
    }
}