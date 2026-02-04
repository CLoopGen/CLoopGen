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
for (y = 0; y < h + 2; y++) {
    for (x = 0; x < 8; x++) {
        int val1 = filter[0] * src[x - 2] + filter[1] * src[x - 1];
        int val2 = filter[2] * src[x    ] + filter[3] * src[x + 1];
        int val3 = filter[4] * src[x + 2] + filter[5] * src[x + 3];
        tmp[x] = cm[(val1 - val2 + val3 + 64) >> 7];
    }
    tmp += 16;
    src += srcstride;
}
}
