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
    const uint8_t *yc = ysrc, *uc = usrc, *vc = vsrc;
    for (i = 0; i < chromWidth; i++) {
        *idst++ = yc[0] + (uc[0] << 8) + (yc[1] << 16) + (vc[0] << 24);
        yc += 2;
        uc++;
        vc++;
    }
    if ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
        usrc += chromStride;
        vsrc += chromStride;
    }
    ysrc += lumStride;
    dst += dstStride;
}

}
