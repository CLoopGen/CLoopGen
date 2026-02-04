#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t linesize;
extern int16_t *block;
extern int x;
extern int y;
extern  uint16_t *tsrc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with flattened indexing and local pointer
    int16_t *bptr = block;
    uint16_t *src_row = tsrc;
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            bptr[x] = (int16_t)src_row[x];
        }
        bptr += 8;
        src_row = (uint16_t*)((uint8_t*)src_row + linesize);
    }
}
