#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src1;
extern uint8_t *src2;
extern int w;
extern int h;
extern int stride;
extern  uint32_t *sq;
extern int acc;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers per row to improve spatial locality
    for (y = 0; y < h; y++) {
        uint8_t *src1_row = &src1[y * stride];
        uint8_t *src2_row = &src2[y * stride];
        for (x = 0; x < w; x++) {
            acc += sq[src1_row[x] - src2_row[x]];
        }
    }
}
