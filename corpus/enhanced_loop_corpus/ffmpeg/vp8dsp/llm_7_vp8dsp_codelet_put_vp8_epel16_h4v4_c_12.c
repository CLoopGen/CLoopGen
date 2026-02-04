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
    uint8_t prev_val = 0;
    for (y = 0; y < h + 4 - 1; y++) {
        for (x = 0; x < 16; x++) {
            int offset = x + 0 * 1;
            int filtered_val = (filter[2] * src[offset] - 
                                filter[1] * src[offset - 1] + 
                                filter[3] * src[offset + 1] - 
                                filter[4] * src[offset + 2] + 64) >> 7;
            uint8_t current = cm[filtered_val];
            tmp[x] = (prev_val + current) >> 1; 
            prev_val = current; 
        }
        tmp += 16;
        src += srcstride;
    }
}
