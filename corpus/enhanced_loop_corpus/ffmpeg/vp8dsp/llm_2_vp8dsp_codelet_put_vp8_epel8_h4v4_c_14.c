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
    for (y = 0; y < h + 4 - 1; y++) {
        uint8_t temp_vals[8];
        for (x = 0; x < 8; x++) {
            int offset = x * srcstride;
            temp_vals[x] = cm[(filter[2] * src[offset] - filter[1] * src[offset - srcstride] + 
                               filter[3] * src[offset + srcstride] - filter[4] * src[offset + 2*srcstride] + 64) >> 7];
        }
        for (x = 0; x < 8; x++) {
            tmp[x] = temp_vals[x];
        }
        tmp += 8;
        src += 1;
    }
}
