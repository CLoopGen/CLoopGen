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
ptrdiff_t offset;
for (y = 0; y < h + 6 - 1; y++) {
    for (x = 0; x < 16; x++) {
        offset = x * srcstride; // Strided access pattern using srcstride on x dimension
        tmp[x] = cm[(filter[2] * src[offset + 0] - filter[1] * src[offset - srcstride] + 
                     filter[3] * src[offset + srcstride] - filter[4] * src[offset + 2*srcstride] + 64) >> 7];
    }
    tmp += 16;
    src += srcstride;
}
}
