#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int16_t dst[64];
int16_t src[64];
uint8_t *permutation;
int i;
unsigned int threshold1;
unsigned int threshold2;

void init_vars() {
    // Initialize thresholds to reasonable values
    threshold1 = 100;
    threshold2 = 200;

    // Allocate and initialize permutation array of size 64
    permutation = (uint8_t*)malloc(64 * sizeof(uint8_t));
    if (!permutation) {
        exit(1);
    }

    // Initialize permutation as identity mapping: permutation[i] = i
    for (int idx = 0; idx < 64; idx++) {
        permutation[idx] = (uint8_t)idx;
    }

    // Initialize src array with sample data
    for (int idx = 0; idx < 64; idx++) {
        src[idx] = (int16_t)(idx * 5); // Arbitrary non-zero pattern
    }

    // Initialize dst to zero
    memset(dst, 0, 64 * sizeof(int16_t));
}