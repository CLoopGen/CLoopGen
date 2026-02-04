#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int linesize;
extern  int16_t block[64];
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // Instead of processing one row per y, we process all rows for each column index
    uint16_t *dst_base = dst;
    for (int x = 0; x < 8; x++) {
        uint16_t *dst_col = dst_base + x;
        int16_t *block_col = block + x;
        for (int y = 0; y < 8; y++) {
            dst_col[y * linesize] += block_col[y * 8];
        }
    }
}
