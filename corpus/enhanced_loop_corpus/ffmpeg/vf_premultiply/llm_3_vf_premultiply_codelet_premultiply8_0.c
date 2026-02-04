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
ptrdiff_t moffset = 0, aoffset = 0, doffset = 0;
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        ptrdiff_t idx = x * 4; // Strided access with step of 4 elements
        if (idx < (ptrdiff_t)w - 3) {
            dst[doffset + idx]     = ((msrc[moffset + idx] * (((asrc[aoffset + idx] >> 1) & 1) + asrc[aoffset + idx])) + 128) >> 8;
            dst[doffset + idx + 1] = ((msrc[moffset + idx + 1] * (((asrc[aoffset + idx + 1] >> 1) & 1) + asrc[aoffset + idx + 1])) + 128) >> 8;
            dst[doffset + idx + 2] = ((msrc[moffset + idx + 2] * (((asrc[aoffset + idx + 2] >> 1) & 1) + asrc[aoffset + idx + 2])) + 128) >> 8;
            dst[doffset + idx + 3] = ((msrc[moffset + idx + 3] * (((asrc[aoffset + idx + 3] >> 1) & 1) + asrc[aoffset + idx + 3])) + 128) >> 8;
        } else {
            // Handle remaining elements with scalar access
            for (int i = idx; i < w; i++) {
                dst[doffset + i] = ((msrc[moffset + i] * (((asrc[aoffset + i] >> 1) & 1) + asrc[aoffset + i])) + 128) >> 8;
            }
            break;
        }
    }
    doffset += dlinesize;
    moffset += mlinesize;
    aoffset += alinesize;
}
}
