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
    uint8_t *src_base = src;
    for (x = 0; x < 16; x++) {
        int offset = x * 4; // Strided access with step of 4 in effective index
        tmp[x] = cm[(filter[2] * src_base[offset/4 + 0] - filter[1] * src_base[offset/4 - 1] + 
                     filter[0] * src_base[offset/4 - 2] + filter[3] * src_base[offset/4 + 1] - 
                     filter[4] * src_base[offset/4 + 2] + filter[5] * src_base[offset/4 + 3] + 64) >> 7];
    }
    tmp += 16;
    src += srcstride;
}
}
