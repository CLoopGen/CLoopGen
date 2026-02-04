#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *mask;
extern int mask_linesize;
extern int l2depth;
extern unsigned int w;
extern unsigned int h;
extern unsigned int xm0;
extern unsigned int xm;
extern unsigned int x;
extern unsigned int y;
extern unsigned int t;
extern unsigned int xmshf;
extern unsigned int xmmod;
extern unsigned int mbits;
extern unsigned int mmult;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    xm = xm0;
    for (x = 0; x < w; x++) {
        uint32_t val1 = ((mask[xm >> xmshf] >> ((~xm & xmmod) << l2depth)) & mbits) * mmult;
        t += val1;
        xm++;
    }
    mask += mask_linesize;
    if (y + 1 < h) {
        xm = xm0;
        for (x = 0; x < w; x++) {
            uint32_t val2 = ((mask[xm >> xmshf] >> ((~xm & xmmod) << l2depth)) & mbits) * mmult;
            t += val2;
            xm++;
        }
        mask += mask_linesize;
    }
}
}
