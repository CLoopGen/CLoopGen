#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

extern u32 x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing elements in a scattered manner (0,4,8,12 etc.),
    // we reorganize the operations to process data in consecutive groups.
    // This improves spatial locality and cache performance.

    u32 temp[16];
    for (int idx = 0; idx < 16; ++idx) {
        temp[idx] = x[idx];
    }

    for (i = 20; i > 0; i -= 2) {
        // Process column-wise slices as consecutive chunks
        for (int col = 0; col < 4; ++col) {
            // First round: vertical diffusion within each column
            temp[col + 0] += temp[col + 4];
            temp[col + 8] ^= temp[col + 0];
            temp[col + 8] = (temp[col + 8] << 16) | (temp[col + 8] >> 16);

            temp[col + 4] += temp[col + 8];
            temp[col + 4] ^= temp[col + 4];
            temp[col + 4] = (temp[col + 4] << 12) | (temp[col + 4] >> 20);

            temp[col + 0] += temp[col + 4];
            temp[col + 8] ^= temp[col + 0];
            temp[col + 8] = (temp[col + 8] << 8) | (temp[col + 8] >> 24);

            temp[col + 4] += temp[col + 8];
            temp[col + 4] ^= temp[col + 4];
            temp[col + 4] = (temp[col + 4] << 7) | (temp[col + 4] >> 25);
        }

        // Second round: diagonal mixing using consecutive indexing
        for (int base = 0; base < 4; ++base) {
            int a = base;
            int b = (base + 1) % 4 + 4;
            int c = (base + 2) % 4 + 8;
            int d = (base + 3) % 4 + 12;

            temp[a] += temp[b];
            temp[d] ^= temp[a];
            temp[d] = (temp[d] << 16) | (temp[d] >> 16);

            temp[b] += temp[d];
            temp[b] ^= temp[c];
            temp[b] = (temp[b] << 12) | (temp[b] >> 20);

            temp[a] += temp[b];
            temp[d] ^= temp[a];
            temp[d] = (temp[d] << 8) | (temp[d] >> 24);

            temp[b] += temp[d];
            temp[b] ^= temp[c];
            temp[b] = (temp[b] << 7) | (temp[b] >> 25);
        }
    }

    // Write back results
    for (int idx = 0; idx < 16; ++idx) {
        x[idx] = temp[idx];
    }
}
