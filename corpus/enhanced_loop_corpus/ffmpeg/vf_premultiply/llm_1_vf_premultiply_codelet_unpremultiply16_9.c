#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int max;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (h > 0 && w > 0) {
    for (y = 0; y < h; y++) {
        x = 0;
        if (y == 0) {
            for (; x < w; x++) {
                if (asrc[x] > 0 && asrc[x] < max)
                    dst[x] = ((msrc[x] * (unsigned int)max / asrc[x]) > (max) ? (max) : (msrc[x] * (unsigned int)max / asrc[x]));
                else
                    dst[x] = msrc[x];
            }
        } else {
            for (; x < w; x++) {
                ptrdiff_t moffset = y * (mlinesize / 2) + x;
                ptrdiff_t aoffset = y * (alinesize / 2) + x;
                ptrdiff_t doffset = y * (dlinesize / 2) + x;
                if (asrc[aoffset] > 0 && asrc[aoffset] < max)
                    dst[doffset] = ((msrc[moffset] * (unsigned int)max / asrc[aoffset]) > max ? max : (msrc[moffset] * (unsigned int)max / asrc[aoffset]));
                else
                    dst[doffset] = msrc[moffset];
            }
        }
    }
}
}
