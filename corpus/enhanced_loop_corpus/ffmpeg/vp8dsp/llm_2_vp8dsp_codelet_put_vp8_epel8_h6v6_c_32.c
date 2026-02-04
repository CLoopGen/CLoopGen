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
    for (y = 0; y < h + 6 - 1; y++) {
        uint8_t temp_val;
        for (x = 0; x < 8; x++) {
            ptrdiff_t offset = x * srcstride; // Convert access to column-major (strided) layout
            temp_val = (filter[2] * src[offset + 0] - 
                        filter[1] * src[offset - srcstride] + 
                        filter[0] * src[offset - 2*srcstride] + 
                        filter[3] * src[offset + srcstride] - 
                        filter[4] * src[offset + 2*srcstride] + 
                        filter[5] * src[offset + 3*srcstride] + 64) >> 7;
            tmp[x] = cm[temp_val];
        }
        tmp += 8;
        src += 1; // Now stepping by element instead of row
    }
}
