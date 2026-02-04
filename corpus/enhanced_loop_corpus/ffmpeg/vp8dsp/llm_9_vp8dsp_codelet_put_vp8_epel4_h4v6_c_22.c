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
for (y = 0; y < h + 8; y += 2) {
    for (x = 0; x < 2; x++) {
        int base = x * 2;
        tmp[base + 0] = cm[(filter[2] * src[base + 0] - filter[1] * src[base - 1] + 
                            filter[3] * src[base + 1] - filter[4] * src[base + 2] + 64) >> 7];
        tmp[base + 1] = cm[(filter[2] * src[base + 1] - filter[1] * src[base + 0] + 
                            filter[3] * src[base + 2] - filter[4] * src[base + 3] + 64) >> 7];
    }
    tmp += 4;
    src += srcstride;
    if (y + 1 < h + 8 && src + srcstride) {
        for (x = 0; x < 2; x++) {
            int base = x * 2;
            tmp[base + 0] = cm[(filter[0] * src[base + 0] + filter[1] * src[base + 1] + 
                                filter[2] * src[base + 2] + filter[3] * src[base + 3] + 64) >> 7];
        }
        tmp += 4;
        src += srcstride;
    }
}
}
