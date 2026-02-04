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
// Use indirect indexing via precomputed indices to alter memory access pattern
unsigned int *indices = (unsigned int*)alloca(w * sizeof(unsigned int));
for (y = 0; y < h; y++) {
    // Generate reversed access pattern (indirect, reverse order)
    xm = xm0;
    for (x = 0; x < w; x++) {
        indices[w - 1 - x] = xm;  // store in reverse order
        xm++;
    }
    for (x = 0; x < w; x++) {
        unsigned int idx = indices[x];
        t += ((mask[idx >> xmshf] >> ((~idx & xmmod) << l2depth)) & mbits) * mmult;
    }
    mask += mask_linesize;
}
}
