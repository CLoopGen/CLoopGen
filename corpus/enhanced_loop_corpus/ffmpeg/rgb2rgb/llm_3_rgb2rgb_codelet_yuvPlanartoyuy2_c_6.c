#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ysrc;
extern  uint8_t *usrc;
extern  uint8_t *vsrc;
extern uint8_t *dst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int dstStride;
extern int vertLumPerChroma;
extern int y;
extern int i;
extern  int chromWidth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    int *idst = (int32_t *)dst;
    // Modified memory access: use array indexing from base pointers with cumulative step tracking
    for (i = 0; i < chromWidth; i++) {
        int y_index = i * 2;
        int uv_index = i;
        *idst++ = ysrc[y_index] + (usrc[uv_index] << 8) + (ysrc[y_index + 1] << 16) + (vsrc[uv_index] << 24);
    }
    if ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
        usrc += chromStride;
        vsrc += chromStride;
    }
    ysrc += lumStride;
    dst += dstStride;
}
}
