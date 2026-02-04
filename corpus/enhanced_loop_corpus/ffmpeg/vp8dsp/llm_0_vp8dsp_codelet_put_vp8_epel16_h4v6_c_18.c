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
    x = 0;
    for (; x < 4; x++) {
        int base_x = x * 4;
        tmp[base_x + 0] = cm[(filter[2] * src[base_x + 0] - filter[1] * src[base_x + 0 - 1] + filter[3] * src[base_x + 0 + 1] - filter[4] * src[base_x + 0 + 2] + 64) >> 7];
        tmp[base_x + 1] = cm[(filter[2] * src[base_x + 1] - filter[1] * src[base_x + 1 - 1] + filter[3] * src[base_x + 1 + 1] - filter[4] * src[base_x + 1 + 2] + 64) >> 7];
        tmp[base_x + 2] = cm[(filter[2] * src[base_x + 2] - filter[1] * src[base_x + 2 - 1] + filter[3] * src[base_x + 2 + 1] - filter[4] * src[base_x + 2 + 2] + 64) >> 7];
        tmp[base_x + 3] = cm[(filter[2] * src[base_x + 3] - filter[1] * src[base_x + 3 - 1] + filter[3] * src[base_x + 3 + 1] - filter[4] * src[base_x + 3 + 2] + 64) >> 7];
    }
    tmp += 16;
    src += srcstride;
}
}
