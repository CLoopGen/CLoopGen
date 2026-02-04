#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i += 2) {
    uint8_t s00 = src[(0) * src_stride + 0];
    uint8_t s01 = src[(0) * src_stride + 1];
    uint8_t s10 = src[(1) * src_stride + 0];
    uint8_t s11 = src[(1) * src_stride + 1];

    uint8_t avg01 = ((unsigned int)s00 + (unsigned int)s11) >> 1;

    uint8_t* dptr = &dst[0];
    dptr[0] = dptr[3] = dptr[9] = dptr[6] = s10;
    dptr[1] = s00;
    dptr[10] = s11;
    dptr[4] = dptr[7] = avg01;
    dptr[11] = dptr[2] = dptr[5] = dptr[8] = s01;

    src += 2;
    dst += 6;
}
}
