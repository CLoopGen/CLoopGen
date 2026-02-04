#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *block;
uint8_t **data;
int top;
int left;
int *stride;
int i;
int j;
int u;
int v;

#define DATA_SIZE (1 << 20) // 1MB per plane
#define STRIDE_ARRAY_SIZE 3

static uint8_t data_storage[3][DATA_SIZE];
static int stride_storage[STRIDE_ARRAY_SIZE];

void init_vars() {
    // Initialize stride values to be larger than typical block sizes to simulate video data planes
    stride_storage[0] = DATA_SIZE / 4;
    stride_storage[1] = DATA_SIZE / 4;
    stride_storage[2] = DATA_SIZE / 4;
    stride = stride_storage;

    // Set top and left within safe bounds so that (top + i) * stride[x] + left + j < DATA_SIZE
    top = 0;
    left = 0;

    // Initialize data pointers to point to the beginning of each plane
    data = malloc(3 * sizeof(uint8_t*));
    if (!data) exit(1);
    for (int idx = 0; idx < 3; idx++) {
        data[idx] = data_storage[idx];
    }

    // Allocate and initialize block as a buffer we can increment
    block = malloc(4 * sizeof(uint8_t));
    if (!block) exit(1);

    // Initialize accumulators
    u = 0;
    v = 0;

    // Ensure all initial accesses are in bounds:
    // Max index: (top + 1) * stride[k] + left + 1 <= 1 * stride[k] + 1 < DATA_SIZE (true)
}