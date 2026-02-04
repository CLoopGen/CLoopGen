#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern int mv[2][4][4];
extern int bx0;
extern int bx1;
extern int by0;
extern int by1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access Pattern via Index Arrays
    // Precompute valid bx and by indices in arrays, then access mv indirectly
    int bx_range[64], by_range[64]; // Assuming max size is 64 for simplicity
    int bx_count = 0, by_count = 0;

    for (int i = bx0; i < bx1; i++) {
        bx_range[bx_count++] = i;
    }
    for (int j = by0; j < by1; j++) {
        by_range[by_count++] = j;
    }

    for (int j = 0; j < by_count; j++) {
        for (int i = 0; i < bx_count; i++) {
            int by_idx = by_range[j];
            int bx_idx = bx_range[i];
            mv[0][by_idx][bx_idx] = mv[1][by_idx][bx_idx] = 0;
        }
    }
}
