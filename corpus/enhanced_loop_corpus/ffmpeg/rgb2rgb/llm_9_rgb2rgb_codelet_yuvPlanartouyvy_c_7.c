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
    // Process two scanlines at a time to reduce loop overhead and increase computation per iteration
    if (y + 1 >= height) {
        // Fallback for odd height
        int *idst = (int32_t *)dst;
        const uint8_t *yc = ysrc, *uc = usrc, *vc = vsrc;
        for (i = 0; i < chromWidth; i++) {
            *idst++ = uc[0] + (yc[0] << 8) + (vc[0] << 16) + (yc[1] << 24);
            yc += 2;
            uc++;
            vc++;
        }
        ysrc += lumStride;
        dst += dstStride;
    } else {
        // Process current and next line together
        int *idst0 = (int32_t *)dst;
        int *idst1 = (int32_t *)(dst + dstStride);
        const uint8_t *yc0 = ysrc, *yc1 = ysrc + lumStride;
        const uint8_t *uc = usrc, *vc = vsrc;

        for (i = 0; i < chromWidth; i++) {
            idst0[i] = uc[0] + (yc0[0] << 8) + (vc[0] << 16) + (yc0[1] << 24);
            idst1[i] = uc[0] + (yc1[0] << 8) + (vc[0] << 16) + (yc1[1] << 24);
        }

        // Update pointers only once per two lines
        if ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
            usrc += chromStride;
            vsrc += chromStride;
        }
        if (((y + 1) & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
            usrc += chromStride;
            vsrc += chromStride;
        }
        ysrc += 2 * lumStride;
        dst += 2 * dstStride;
    }
}
}
