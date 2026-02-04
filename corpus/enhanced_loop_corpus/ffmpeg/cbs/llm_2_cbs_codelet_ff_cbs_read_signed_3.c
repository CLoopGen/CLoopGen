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
    // Variant 1: Consecutive memory access with reverse index mapping
    // Instead of accessing bits in forward order based on decreasing bit position,
    // we reverse the logic to write from high to low index, but still fill consecutively.
    int idx = 0;
    for (i = width - 1; i >= 0; i--) {
        bits[idx++] = value & (1U << i) ? '1' : '0';
    }
}
