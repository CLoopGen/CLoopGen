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
for (y = 0; y < h + 6; y += 2) {
    for (x = 0; x < 32; x += 4) {
        tmp[x + 0] = cm[(filter[2] * src[x + 0] - filter[1] * src[x - 1] + 
                         filter[3] * src[x + 1] - filter[4] * src[x + 2] + 64) >> 7];
        tmp[x + 1] = cm[(filter[2] * src[x + 1] - filter[1] * src[x + 0] + 
                         filter[3] * src[x + 2] - filter[4] * src[x + 3] + 64) >> 7];
        tmp[x + 2] = cm[(filter[2] * src[x + 2] - filter[1] * src[x + 1] + 
                         filter[3] * src[x + 3] - filter[4] * src[x + 4] + 64) >> 7];
        tmp[x + 3] = cm[(filter[2] * src[x + 3] - filter[1] * src[x + 2] + 
                         filter[3] * src[x + 4] - filter[4] * src[x + 5] + 64) >> 7];
    }
    for (x = 0; x < 32; x++) {
        tmp[x] = cm[(tmp[x] + 1) >> 1]; // Post-processing pass to increase compute intensity
    }
    tmp += 32;
    src += 2 * srcstride;
}
}
