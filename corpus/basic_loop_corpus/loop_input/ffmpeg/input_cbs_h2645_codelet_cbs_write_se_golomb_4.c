#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 20000000; // ~20 million iterations to target ~0.01 sec runtime
uint32_t uvalue = 0x12345678;
char bits[65] = {0};

int i;

void init_vars() {
    // Ensure bits array is large enough for the loop: bits[len + i + 1]
    // Maximum index accessed: len + (len - 1) + 1 = 2 * len
    // So we need at least 2 * len + 1 bytes for bits

    // Reallocate or redefine bits to avoid out-of-bounds access
    // But since bits is declared as [65] in extern, we must match that size
    // Therefore, we must constrain len so that len + i + 1 < 65

    // Correction: The original extern declaration says bits[65], so we cannot exceed that.
    // Hence, the maximum allowed index is 64.
    // In loop: bits[len + i + 1] -> max index when i = len-1: len + (len-1) + 1 = 2*len
    // So: 2*len <= 64  => len <= 32

    // We must reduce len to satisfy memory safety with fixed-size bits[65]
    len = 32;

    // Now maximum index: len + i + 1 = 32 + 31 + 1 = 64 -> valid (0..64)
    if (bits[0] == 0) {
        // Initialize bits to safe values
        for (int j = 0; j < 65; j++) {
            bits[j] = 'X'; // Placeholder, will be overwritten in loop
        }
    }

    uvalue = 0x12345678;
    i = 0;
}