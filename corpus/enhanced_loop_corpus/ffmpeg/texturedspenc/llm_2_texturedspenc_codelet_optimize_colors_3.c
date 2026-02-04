#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int cov[6];
extern int mu[3];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointer and using linear index
    uint8_t *base = block + (y * stride) * 4; // Base for current row, though y is reset here
    for (y = 0; y < 4; y++) {
        uint8_t *row = base + y * stride * 4;
        for (x = 0; x < 4; x++) {
            int offset = x * 4;
            int r = row[offset + 0] - mu[0];
            int g = row[offset + 1] - mu[1];
            int b = row[offset + 2] - mu[2];
            cov[0] += r * r;
            cov[1] += r * g;
            cov[2] += r * b;
            cov[3] += g * g;
            cov[4] += g * b;
            cov[5] += b * b;
        }
    }
}
