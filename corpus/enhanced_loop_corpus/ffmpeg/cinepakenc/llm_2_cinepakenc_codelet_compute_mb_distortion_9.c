#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *a_data[4];
extern int a_linesize[4];
extern uint8_t *b_data[4];
extern int b_linesize[4];
extern int x;
extern int y;
extern int p;
extern int d;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (flattened indexing with precomputed offsets)
    int offset_a, offset_b;
    for (p = 1; p <= 2; p++) {
        offset_a = 0;
        offset_b = 0;
        for (y = 0; y < 4 / 2; y++) {
            for (x = 0; x < 4 / 2; x++) {
                d = a_data[p][offset_a + x] - b_data[p][offset_b + x];
                ret += d * d;
            }
            offset_a += a_linesize[p];
            offset_b += b_linesize[p];
        }
    }
}
