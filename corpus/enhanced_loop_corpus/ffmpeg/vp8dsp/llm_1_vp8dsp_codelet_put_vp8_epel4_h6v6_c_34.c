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
    for (int offset = 0; offset < 4; offset++) {
        for (x = offset; x < offset + 1; x++)
            tmp[x] = cm[(filter[2] * src[x] - filter[1] * src[x - 1] + filter[0] * src[x - 2] + filter[3] * src[x + 1] - filter[4] * src[x + 2] + filter[5] * src[x + 3] + 64) >> 7];
    }
    tmp += 4;
    src += srcstride;
}
}
