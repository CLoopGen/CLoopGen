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
for (y = 0; y < height; y += vertLumPerChroma) {
    const uint8_t *yc = ysrc;
    const uint8_t *uc = usrc;
    const uint8_t *vc = vsrc;
    int *idst = (int32_t *)dst;
    for (i = 0; i < chromWidth; i++) {
        int pixel = uc[i] + (yc[i*2] << 8) + (vc[i] << 16) + (yc[i*2+1] << 24);
        *(idst + i) = pixel;
        *(idst + i + dstStride/4) = pixel; // Write same pixel to next output row (simulating vertical replication)
    }
    usrc += chromStride;
    vsrc += chromStride;
    ysrc += lumStride * vertLumPerChroma;
    dst += dstStride * 2;
}
// Handle potential odd height by adjusting original variables if needed
// This variant assumes height is multiple of vertLumPerChroma for correctness
}
