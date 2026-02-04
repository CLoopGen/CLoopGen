#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access (stride of 2, then fill gaps in second pass)
    // Simulate a strided pattern by writing every second element first, then filling in
    int j;
    // First pass: write even indices with higher-order bits
    for (j = 0; j < width; j += 2) {
        int bit_pos = width - j - 1;
        if (bit_pos >= 0)
            bits[j] = value & (1U << bit_pos) ? '1' : '0';
    }
    // Second pass: write odd indices
    for (j = 1; j < width; j += 2) {
        int bit_pos = width - j - 1;
        if (bit_pos >= 0)
            bits[j] = value & (1U << bit_pos) ? '1' : '0';
    }
}
