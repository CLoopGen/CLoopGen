#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int radius;
extern  uint8_t *c[];
extern  uint8_t *src;
extern int stride;
extern int x;
extern int y;
extern int h;
extern int bpc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Indirect memory access using precomputed offsets
    // Simulate gather-style access via an offset table
    static int offsets[256]; // Assuming max radius*2+1 <= 256
    if (offsets[0] == 0) { // Initialize once
        for (int j = 0; j < 256; j++) {
            int idx = x + j - radius;
            idx = (idx < 0) ? -idx : idx;
            idx = (idx >= h) ? 2 * h - 1 - idx : idx;
            offsets[j] = idx * stride + y * bpc;
        }
    }
    for (i = 0; i < radius * 2 + 1; i++) {
        c[i] = src + offsets[i];
    }
}
