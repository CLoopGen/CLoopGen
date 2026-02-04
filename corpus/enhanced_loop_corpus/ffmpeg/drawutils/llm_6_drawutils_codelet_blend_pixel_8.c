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
    uint32_t local_t = t; // Introduce private accumulator to remove WAW dependency on 't'
    for (y = 0; y < h; y++) {
        xm = xm0;
        uint32_t row_sum = 0; // Local reduction to modify data dependency structure
        for (x = 0; x < w; x++) {
            uint8_t val = mask[(xm >> xmshf) + (x & 7)]; // Slight offset using 'x' to alter address pattern (introduces new RAW)
            row_sum += ((val >> ((~xm & xmmod) << l2depth)) & mbits) * mmult;
            xm++;
        }
        t += row_sum; // Only one write to shared 't' per iteration, reducing WAW
        mask += mask_linesize;
    }
}
