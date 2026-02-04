#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 256 * 1024 * 1024; // 256 million elements to target ~0.01 sec runtime
uint32_t magnitude = 0xABCDEF12;
char bits[33];
int i;

void init_vars() {
    // Ensure width does not exceed the actual buffer size of bits array
    if (width > 32) {
        width = 32;
    }
    // Initialize magnitude with non-zero pattern for meaningful bit extraction
    magnitude = 0xABCDEF12;
    // Initialize bits array to avoid undefined behavior
    for (int j = 0; j < 33; j++) {
        bits[j] = 'X';
    }
    // Initialize loop index
    i = 0;
}