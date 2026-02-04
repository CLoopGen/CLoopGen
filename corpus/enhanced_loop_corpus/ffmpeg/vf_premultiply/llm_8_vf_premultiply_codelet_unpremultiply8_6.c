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
for (y = 0; y < h; y++) {
    for (x = 0; x < w - (w % 4); x += 4) {
        // Unroll loop by factor of 4 to increase computational intensity
        int val0 = asrc[x + 0];
        int val1 = asrc[x + 1];
        int val2 = asrc[x + 2];
        int val3 = asrc[x + 3];

        if (val0 > 0 && val0 < 255)
            dst[x + 0] = (msrc[x + 0] * 255 / val0) > 255 ? 255 : (msrc[x + 0] * 255 / val0);
        else
            dst[x + 0] = msrc[x + 0];

        if (val1 > 0 && val1 < 255)
            dst[x + 1] = (msrc[x + 1] * 255 / val1) > 255 ? 255 : (msrc[x + 1] * 255 / val1);
        else
            dst[x + 1] = msrc[x + 1];

        if (val2 > 0 && val2 < 255)
            dst[x + 2] = (msrc[x + 2] * 255 / val2) > 255 ? 255 : (msrc[x + 2] * 255 / val2);
        else
            dst[x + 2] = msrc[x + 2];

        if (val3 > 0 && val3 < 255)
            dst[x + 3] = (msrc[x + 3] * 255 / val3) > 255 ? 255 : (msrc[x + 3] * 255 / val3);
        else
            dst[x + 3] = msrc[x + 3];
    }
    // Handle remaining elements
    for (; x < w; x++) {
        if (asrc[x] > 0 && asrc[x] < 255)
            dst[x] = ((msrc[x] * 255 / asrc[x]) > 255 ? 255 : (msrc[x] * 255 / asrc[x]));
        else
            dst[x] = msrc[x];
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
