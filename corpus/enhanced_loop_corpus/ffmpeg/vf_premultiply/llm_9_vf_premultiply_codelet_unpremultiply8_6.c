#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective trip count and increase arithmetic per iteration
for (y = 0; y < h; y += 2) {
    uint8_t *dst0 = dst;
    uint8_t *dst1 = dst + dlinesize;
    uint8_t *msrc0 = msrc;
    uint8_t *msrc1 = msrc + mlinesize;
    uint8_t *asrc0 = asrc;
    uint8_t *asrc1 = asrc + alinesize;

    for (x = 0; x < w; x++) {
        // Process two rows simultaneously to increase computation per loop iteration
        if (asrc0[x] > 0 && asrc0[x] < 255)
            dst0[x] = (msrc0[x] * 255 / asrc0[x]) > 255 ? 255 : (msrc0[x] * 255 / asrc0[x]);
        else
            dst0[x] = msrc0[x];

        if (y + 1 < h) { // Prevent overflow on last row
            if (asrc1[x] > 0 && asrc1[x] < 255)
                dst1[x] = (msrc1[x] * 255 / asrc1[x]) > 255 ? 255 : (msrc1[x] * 255 / asrc1[x]);
            else
                dst1[x] = msrc1[x];
        }
    }

    dst += 2 * dlinesize;
    msrc += 2 * mlinesize;
    asrc += 2 * alinesize;
}
}
