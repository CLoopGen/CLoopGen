#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing reorganization
    // Instead of using strided access via pointer arithmetic, use flat indexing for tmp and src
    // This improves predictability and enables better vectorization
    uint8_t *src_base = src;
    uint8_t *tmp_base = tmp;
    for (y = 0; y < h + 4 - 1; y++) {
        ptrdiff_t src_offset = y * srcstride;
        int tmp_offset = y * 4;
        for (x = 0; x < 4; x++) {
            int idx = x + src_offset;
            tmp_base[tmp_offset + x] = cm[(filter[2] * src_base[idx] -
                                          filter[1] * src_base[idx - 1] +
                                          filter[3] * src_base[idx + 1] -
                                          filter[4] * src_base[idx + 2] + 64) >> 7];
        }
    }
}
