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
    x = 0;
    if (w >= 4) {
        for (; x <= w - 4; x += 4) {
            int t0 = asrc[x+0], t1 = asrc[x+1], t2 = asrc[x+2], t3 = asrc[x+3];
            if (t0 > 0 && t0 < 255)
                dst[x+0] = (((msrc[x+0] - 128) * 255 / t0 + 128) > 255 ? 255 : ((msrc[x+0] - 128) * 255 / t0 + 128));
            else
                dst[x+0] = msrc[x+0];

            if (t1 > 0 && t1 < 255)
                dst[x+1] = (((msrc[x+1] - 128) * 255 / t1 + 128) > 255 ? 255 : ((msrc[x+1] - 128) * 255 / t1 + 128));
            else
                dst[x+1] = msrc[x+1];

            if (t2 > 0 && t2 < 255)
                dst[x+2] = (((msrc[x+2] - 128) * 255 / t2 + 128) > 255 ? 255 : ((msrc[x+2] - 128) * 255 / t2 + 128));
            else
                dst[x+2] = msrc[x+2];

            if (t3 > 0 && t3 < 255)
                dst[x+3] = (((msrc[x+3] - 128) * 255 / t3 + 128) > 255 ? 255 : ((msrc[x+3] - 128) * 255 / t3 + 128));
            else
                dst[x+3] = msrc[x+3];
        }
    }
    for (; x < w; x++) {
        if (asrc[x] > 0 && asrc[x] < 255)
            dst[x] = (((msrc[x] - 128) * 255 / asrc[x] + 128) > (255) ? (255) : ((msrc[x] - 128) * 255 / asrc[x] + 128));
        else
            dst[x] = msrc[x];
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
