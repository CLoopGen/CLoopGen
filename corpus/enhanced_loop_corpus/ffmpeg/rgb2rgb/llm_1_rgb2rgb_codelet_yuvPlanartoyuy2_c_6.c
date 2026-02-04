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
    const uint8_t *yc = ysrc;
    const uint8_t *uc_start = usrc;
    const uint8_t *vc_start = vsrc;
    for (int j = 0; j < chromWidth; j++) {
        const uint8_t *uc = uc_start + j;
        const uint8_t *vc = vc_start + j;
        const uint8_t *yc_local = yc + 2*j;
        idst[j] = yc_local[0] + (uc[0] << 8) + (yc_local[1] << 16) + (vc[0] << 24);
    }
    if ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
        usrc += chromStride;
        vsrc += chromStride;
    }
    ysrc += lumStride;
    dst += dstStride;
}
}
