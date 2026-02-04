#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int *qmat;
uint8_t *scantable;
unsigned int threshold1;
unsigned int threshold2;
int start_i;
int last_non_zero;
int i;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256MB total allocation target
    const size_t block_size = data_size / 3; // Approximate size for each array

    // Allocate and initialize block (int16_t array of size 64 is implied by i=63)
    block = aligned_alloc(32, sizeof(int16_t) * 64);
    for (int idx = 0; idx < 64; idx++) {
        block[idx] = (int16_t)(idx % 256 - 128);
    }

    // Allocate and initialize qmat (must be at least 64 elements to match j = scantable[i])
    qmat = aligned_alloc(32, sizeof(int) * 64);
    for (int idx = 0; idx < 64; idx++) {
        qmat[idx] = (int)(idx + 1);
    }

    // Allocate and initialize scantable (maps 64 indices)
    scantable = aligned_alloc(16, sizeof(uint8_t) * 64);
    for (int idx = 0; idx < 64; idx++) {
        scantable[idx] = (uint8_t)(63 - idx); // Reverse order ensures access within block bounds
    }

    // Initialize thresholds and loop control variables
    threshold1 = 1;
    threshold2 = 2;
    start_i = 0; // Ensures loop runs from 63 down to 0
    last_non_zero = -1;
    i = 63;
}