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
    for (x = 0; x < w - 3; x += 4) {
        // Process 4 elements at a time with consecutive access
        if (asrc[x] > 0 && asrc[x] < 255)
            dst[x] = (((msrc[x] - 128) * 255 / asrc[x] + 128) > 255 ? 255 : ((msrc[x] - 128) * 255 / asrc[x] + 128));
        else
            dst[x] = msrc[x];

        if (asrc[x+1] > 0 && asrc[x+1] < 255)
            dst[x+1] = (((msrc[x+1] - 128) * 255 / asrc[x+1] + 128) > 255 ? 255 : ((msrc[x+1] - 128) * 255 / asrc[x+1] + 128));
        else
            dst[x+1] = msrc[x+1];

        if (asrc[x+2] > 0 && asrc[x+2] < 255)
            dst[x+2] = (((msrc[x+2] - 128) * 255 / asrc[x+2] + 128) > 255 ? 255 : ((msrc[x+2] - 128) * 255 / asrc[x+2] + 128));
        else
            dst[x+2] = msrc[x+2];

        if (asrc[x+3] > 0 && asrc[x+3] < 255)
            dst[x+3] = (((msrc[x+3] - 128) * 255 / asrc[x+3] + 128) > 255 ? 255 : ((msrc[x+3] - 128) * 255 / asrc[x+3] + 128));
        else
            dst[x+3] = msrc[x+3];
    }
    // Handle remaining elements
    for (; x < w; x++) {
        if (asrc[x] > 0 && asrc[x] < 255)
            dst[x] = (((msrc[x] - 128) * 255 / asrc[x] + 128) > 255 ? 255 : ((msrc[x] - 128) * 255 / asrc[x] + 128));
        else
            dst[x] = msrc[x];
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
