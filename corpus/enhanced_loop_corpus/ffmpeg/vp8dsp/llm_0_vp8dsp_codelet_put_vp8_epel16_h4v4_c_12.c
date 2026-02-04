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
    tmp[y * 16 + 0] = cm[(filter[2] * src[0] - filter[1] * src[-1] + filter[3] * src[1] - filter[4] * src[2] + 64) >> 7];
    tmp[y * 16 + 1] = cm[(filter[2] * src[1] - filter[1] * src[0] + filter[3] * src[2] - filter[4] * src[3] + 64) >> 7];
    tmp[y * 16 + 2] = cm[(filter[2] * src[2] - filter[1] * src[1] + filter[3] * src[3] - filter[4] * src[4] + 64) >> 7];
    tmp[y * 16 + 3] = cm[(filter[2] * src[3] - filter[1] * src[2] + filter[3] * src[4] - filter[4] * src[5] + 64) >> 7];
    tmp[y * 16 + 4] = cm[(filter[2] * src[4] - filter[1] * src[3] + filter[3] * src[5] - filter[4] * src[6] + 64) >> 7];
    tmp[y * 16 + 5] = cm[(filter[2] * src[5] - filter[1] * src[4] + filter[3] * src[6] - filter[4] * src[7] + 64) >> 7];
    tmp[y * 16 + 6] = cm[(filter[2] * src[6] - filter[1] * src[5] + filter[3] * src[7] - filter[4] * src[8] + 64) >> 7];
    tmp[y * 16 + 7] = cm[(filter[2] * src[7] - filter[1] * src[6] + filter[3] * src[8] - filter[4] * src[9] + 64) >> 7];
    tmp[y * 16 + 8] = cm[(filter[2] * src[8] - filter[1] * src[7] + filter[3] * src[9] - filter[4] * src[10] + 64) >> 7];
    tmp[y * 16 + 9] = cm[(filter[2] * src[9] - filter[1] * src[8] + filter[3] * src[10] - filter[4] * src[11] + 64) >> 7];
    tmp[y * 16 + 10] = cm[(filter[2] * src[10] - filter[1] * src[9] + filter[3] * src[11] - filter[4] * src[12] + 64) >> 7];
    tmp[y * 16 + 11] = cm[(filter[2] * src[11] - filter[1] * src[10] + filter[3] * src[12] - filter[4] * src[13] + 64) >> 7];
    tmp[y * 16 + 12] = cm[(filter[2] * src[12] - filter[1] * src[11] + filter[3] * src[13] - filter[4] * src[14] + 64) >> 7];
    tmp[y * 16 + 13] = cm[(filter[2] * src[13] - filter[1] * src[12] + filter[3] * src[14] - filter[4] * src[15] + 64) >> 7];
    tmp[y * 16 + 14] = cm[(filter[2] * src[14] - filter[1] * src[13] + filter[3] * src[15] - filter[4] * src[16] + 64) >> 7];
    tmp[y * 16 + 15] = cm[(filter[2] * src[15] - filter[1] * src[14] + filter[3] * src[16] - filter[4] * src[17] + 64) >> 7];
    src += srcstride;
}
}
