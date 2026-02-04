#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *top;
extern int16_t *bottom;
extern int i;
extern int a;
extern int b;
extern int c;
extern int d;
extern int d1;
extern int d2;
extern int rnd1;
extern int rnd2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Indirect Access via Index Array
    // Use a lookup table to access non-contiguous memory locations in a strided pattern.
    // Simulates irregular access patterns common in sparse computations.
    const int offsets[8] = {0, 8, 16, 24, 32, 40, 48, 56}; // Stride of 8
    for (i = 0; i < 8; i++) {
        int idx_top = offsets[i];      // Indirect indexing into top
        int idx_bot = offsets[7 - i];  // Reverse order for bottom
        a = top[idx_top];
        b = top[idx_top + 8];
        c = bottom[idx_bot];
        d = bottom[idx_bot + 8];
        d1 = a - d;
        d2 = a - d + b - c;
        top[idx_top] = ((a * 8) - d1 + rnd1) >> 3;
        top[idx_top + 8] = ((b * 8) - d2 + rnd2) >> 3;
        bottom[idx_bot] = ((c * 8) + d2 + rnd1) >> 3;
        bottom[idx_bot + 8] = ((d * 8) + d1 + rnd2) >> 3;
        rnd2 = 7 - rnd2;
        rnd1 = 7 - rnd1;
    }
}
