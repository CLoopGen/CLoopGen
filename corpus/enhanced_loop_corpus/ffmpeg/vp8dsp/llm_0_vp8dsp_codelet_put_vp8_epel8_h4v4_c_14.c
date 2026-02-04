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
for (y = 0; y < h + 4 - 1; y++) {
    tmp[y * 8 + 0] = cm[(filter[2] * src[0] - filter[1] * src[-1] + filter[3] * src[1] - filter[4] * src[2] + 64) >> 7];
    tmp[y * 8 + 1] = cm[(filter[2] * src[1] - filter[1] * src[0] + filter[3] * src[2] - filter[4] * src[3] + 64) >> 7];
    tmp[y * 8 + 2] = cm[(filter[2] * src[2] - filter[1] * src[1] + filter[3] * src[3] - filter[4] * src[4] + 64) >> 7];
    tmp[y * 8 + 3] = cm[(filter[2] * src[3] - filter[1] * src[2] + filter[3] * src[4] - filter[4] * src[5] + 64) >> 7];
    tmp[y * 8 + 4] = cm[(filter[2] * src[4] - filter[1] * src[3] + filter[3] * src[5] - filter[4] * src[6] + 64) >> 7];
    tmp[y * 8 + 5] = cm[(filter[2] * src[5] - filter[1] * src[4] + filter[3] * src[6] - filter[4] * src[7] + 64) >> 7];
    tmp[y * 8 + 6] = cm[(filter[2] * src[6] - filter[1] * src[5] + filter[3] * src[7] - filter[4] * src[8] + 64) >> 7];
    tmp[y * 8 + 7] = cm[(filter[2] * src[7] - filter[1] * src[6] + filter[3] * src[8] - filter[4] * src[9] + 64) >> 7];
    src += srcstride;
}
}
