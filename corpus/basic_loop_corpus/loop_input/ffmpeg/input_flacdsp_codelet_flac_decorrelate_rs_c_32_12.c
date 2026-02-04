#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 16777216; // ~64 MB input (16M * 4 bytes per int), allows for reasonable runtime (~0.01 sec estimate)
int shift = 1;
int32_t *samples;
int i;

int32_t **in;

void init_vars() {
    // Allocate space for two rows of int32_t pointers
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    if (!in) exit(1);

    // Allocate each row with `len` elements
    for (int row = 0; row < 2; row++) {
        in[row] = (int32_t*)calloc(len, sizeof(int32_t));
        if (!in[row]) exit(1);
        // Initialize with sample data to avoid all zeros
        for (int j = 0; j < len; j++) {
            in[row][j] = rand() & 0xFFFFF; // random 20-bit values
        }
    }

    // Allocate samples: 2 outputs per iteration => 2 * len entries
    samples = (int32_t*)malloc(2 * len * sizeof(int32_t));
    if (!samples) exit(1);
}