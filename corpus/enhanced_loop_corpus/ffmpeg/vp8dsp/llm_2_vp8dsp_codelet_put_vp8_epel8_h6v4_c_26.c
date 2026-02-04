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
    // Variant 1: Consecutive memory access with precomputed source indices
    uint8_t *src_base = src;
    for (y = 0; y < h + 4 - 1; y++) {
        uint8_t local_tmp[8];
        const ptrdiff_t offset = y * srcstride;
        for (x = 0; x < 8; x++) {
            int32_t sum = filter[2] * src_base[offset + x] -
                          filter[1] * src_base[offset + x - 1] +
                          filter[0] * src_base[offset + x - 2] +
                          filter[3] * src_base[offset + x + 1] -
                          filter[4] * src_base[offset + x + 2] +
                          filter[5] * src_base[offset + x + 3];
            local_tmp[x] = cm[(sum + 64) >> 7];
        }
        for (x = 0; x < 8; x++) {
            tmp[x] = local_tmp[x];
        }
        tmp += 8;
    }
}
