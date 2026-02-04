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
    for (x = 0; x < 4; x++) {
        uint8_t val0 = src[x];
        uint8_t val1 = src[x - 1];
        uint8_t val2 = src[x + 1];
        uint8_t val3 = src[x + 2];
        int filtered = filter[2] * val0 - filter[1] * val1 + filter[3] * val2 - filter[4] * val3;
        tmp[x] = cm[(filtered + 64) >> 7];
    }
    tmp += 4;
    src += srcstride;
}
}
