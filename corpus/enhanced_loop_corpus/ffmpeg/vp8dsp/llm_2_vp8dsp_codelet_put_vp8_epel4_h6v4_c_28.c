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
        uint8_t temp_vals[4];
        for (x = 0; x < 4; x++) {
            ptrdiff_t offset = x * 1;
            temp_vals[x] = cm[(filter[2] * src[offset + 0] - filter[1] * src[offset - 1] + 
                              filter[0] * src[offset - 2] + filter[3] * src[offset + 1] - 
                              filter[4] * src[offset + 2] + filter[5] * src[offset + 3] + 64) >> 7];
        }
        for (x = 0; x < 4; x++) {
            tmp[x] = temp_vals[x];
        }
        tmp += 4;
        src += srcstride;
    }
}
