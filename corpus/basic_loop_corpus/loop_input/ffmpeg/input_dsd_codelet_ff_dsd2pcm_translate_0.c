#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

float ctables[6][256];
uint8_t buf[16];
unsigned int pos;
unsigned int i;
double sum;

void init_vars() {
    // Initialize ctables with dummy data to avoid uninitialized values
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 256; col++) {
            ctables[row][col] = (float)(row + 1) * 0.5f;
        }
    }

    // Initialize buf with safe values
    for (int idx = 0; idx < 16; idx++) {
        buf[idx] = (uint8_t)(idx % 256);
    }

    // Set pos such that all buffer accesses are within bounds
    // Loop runs for ((48 + 7) / 8) = 7 iterations
    // Index expressions: (pos - i) & 15 and (pos - 13 + i) & 15
    // To keep indices valid, we need pos >= 13 so that (pos - 13) >= 0
    pos = 15;

    // Initialize sum to zero before accumulation
    sum = 0.0;
}