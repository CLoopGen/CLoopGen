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
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    ptrdiff_t stride = srcstride;
    for (y = 0; y < h + 4 - 1; y++) {
        const uint8_t *s = src;
        for (x = 0; x < 16; x++) {
            // Use strided access through explicit offsets from base pointer
            int val = filter[2] * s[x] -
                      filter[1] * s[x - 1] +
                      filter[3] * s[x + 1] -
                      filter[4] * s[x + 2];
            tmp[x] = cm[(val + 64) >> 7];
        }
        tmp += 16;
        src += stride;
    }
}
