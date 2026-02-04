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
for (y = 0; y < height; y += 2) {
    // Process two scanlines at a time to reduce loop overhead and increase stride utilization
    uint8_t *dst1 = dst;
    uint8_t *dst2 = (y + 1 < height) ? dst + dstStride : dst;

    int *idst1 = (int32_t *)dst1;
    int *idst2 = (int32_t *)dst2;

    const uint8_t *yc1 = ysrc;
    const uint8_t *yc2 = (y + 1 < height) ? ysrc + lumStride : ysrc;
    const uint8_t *uc = usrc;
    const uint8_t *vc = vsrc;

    for (i = 0; i < chromWidth; i++) {
        idst1[i] = yc1[0] + (uc[0] << 8) + (yc1[1] << 16) + (vc[0] << 24);
        if (y + 1 < height) {
            idst2[i] = yc2[0] + (uc[0] << 8) + (yc2[1] << 16) + (vc[0] << 24);
        }
        yc1 += 2;
        yc2 += 2;
        uc++;
        vc++;
    }

    // Update chroma pointers every vertLumPerChroma lines (applies to both lines)
    if (((y + 1) & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
        usrc += chromStride;
        vsrc += chromStride;
    }
    if (((y + 2) & (vertLumPerChroma - 1)) == vertLumPerChroma - 1 && y + 1 < height) {
        usrc += chromStride;
        vsrc += chromStride;
    }

    ysrc += 2 * lumStride;
    dst += 2 * dstStride;
}
}
