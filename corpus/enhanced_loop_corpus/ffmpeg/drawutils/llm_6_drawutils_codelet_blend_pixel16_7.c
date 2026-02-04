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
    uint32_t local_t = 0;
    for (y = 0; y < h; y++) {
        xm = xm0;
        for (x = 0; x < w; x++) {
            uint8_t val = mask[xm >> xmshf];
            uint32_t shifted = val >> ((~xm & xmmod) << l2depth);
            uint32_t masked = shifted & mbits;
            local_t += masked * mmult;
            xm++;
        }
        mask += mask_linesize;
    }
    t += local_t;
}
