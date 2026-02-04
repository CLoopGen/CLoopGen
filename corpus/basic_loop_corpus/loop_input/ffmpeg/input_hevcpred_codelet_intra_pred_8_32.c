#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint8_t *top;
uint8_t *filtered_top;

void init_vars() {
    // Allocate approximately 64MB of data to achieve ~0.01s runtime on modern CPUs
    size = 16777216; // 16 * 1024 * 1024, chosen so that total data is large enough

    // Adjust size for the loop: we access i+1 and i-1, so valid index range must be [1, size*2-2]
    // We set problem size such that loop runs from 2*size - 2 down to 0
    // To prevent out-of-bounds, we require:
    //   i-1 >= 0 --> i >= 1, but loop goes down to 0 -> so we need top[-1] to be invalid
    // Therefore, we shift indexing: make top point to middle of allocated buffer

    // Let allocated_size cover [-1, 2*size - 1] -> indices: -1, 0, ..., 2*size-1
    // So we need buffer of size (2*size + 1)
    int buffer_size = 2 * size + 1;

    uint8_t *raw_top = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));
    if (!raw_top) exit(1);

    top = raw_top + 1; // Now top[i-1] when i=0 accesses raw_top[0], which is safe
    // top[-1] now points to raw_top[0], top[0] to raw_top[1], etc.

    filtered_top = (uint8_t*)calloc(2 * size, sizeof(uint8_t));
    if (!filtered_top) exit(1);

    // Initialize top with some data to avoid all zeros
    for (int j = 0; j < 2 * size; j++) {
        top[j] = rand() & 0xFF;
    }
    // Ensure boundaries are accessible
    top[-1] = rand() & 0xFF;
    top[2*size - 1 + 1] = rand() & 0xFF; // top[2*size] is accessed via top[i+1] when i=2*size-1

    i = 0; // will be set by loop, but initialize anyway
}