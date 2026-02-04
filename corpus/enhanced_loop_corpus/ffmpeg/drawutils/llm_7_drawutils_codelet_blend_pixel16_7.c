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
    uint32_t temp_accum = 0;
    uint32_t prev_xm = xm0;
    for (y = 0; y < h; y++) {
        xm = prev_xm;
        for (x = 0; x < w; x++) {
            uint32_t index = xm >> xmshf;
            uint32_t shift_amount = ((~xm & xmmod) << l2depth);
            uint32_t data = (mask[index] >> shift_amount) & mbits;
            temp_accum += data * mmult;
            prev_xm = xm; // Introduce artificial dependency: current xm depends on last iteration's xm
            xm = prev_xm + 1;
        }
        mask += mask_linesize;
    }
    t = temp_accum; // Eliminate accumulation into global `t`, write once at end
}
