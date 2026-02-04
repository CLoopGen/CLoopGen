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
    // Variant 1: Consecutive memory access with unrolled filtering (consecutive load pattern)
    for (y = 0; y < h + 4 - 1; y++) {
        uint8_t local_src[20];
        // Preload a block of src into local consecutive array to enable linear access
        for (int i = 0; i < 20; i++) {
            local_src[i] = src[i];
        }
        for (x = 0; x < 16; x++) {
            int val = filter[2] * local_src[x + 0] -
                      filter[1] * local_src[x - 1] +
                      filter[3] * local_src[x + 1] -
                      filter[4] * local_src[x + 2];
            tmp[x] = cm[(val + 64) >> 7];
        }
        tmp += 16;
        src += srcstride;
    }
}
