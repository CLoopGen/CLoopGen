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
extern int offset;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        if (y + 1 < h) {
            // Process current row y
            if (asrc[x] > 0 && asrc[x] < max) {
                uint16_t val = (msrc[x] - offset) > 0 ? (msrc[x] - offset) : 0;
                dst[x] = (val * (unsigned int)max / asrc[x] + offset) > max ? max : (val * (unsigned int)max / asrc[x] + offset);
                dst[x] = dst[x] > 0 ? dst[x] : 0;
            } else {
                dst[x] = msrc[x];
            }

            // Process next row y+1
            uint16_t *msrc_next = msrc + mlinesize / 2;
            uint16_t *asrc_next = asrc + alinesize / 2;
            uint16_t *dst_next = dst + dlinesize / 2;

            if (asrc_next[x] > 0 && asrc_next[x] < max) {
                uint16_t val = (msrc_next[x] - offset) > 0 ? (msrc_next[x] - offset) : 0;
                dst_next[x] = (val * (unsigned int)max / asrc_next[x] + offset) > max ? max : (val * (unsigned int)max / asrc_next[x] + offset);
                dst_next[x] = dst_next[x] > 0 ? dst_next[x] : 0;
            } else {
                dst_next[x] = msrc_next[x];
            }
        } else {
            // Handle last odd row when h is odd
            if (asrc[x] > 0 && asrc[x] < max) {
                uint16_t val = (msrc[x] - offset) > 0 ? (msrc[x] - offset) : 0;
                dst[x] = (val * (unsigned int)max / asrc[x] + offset) > max ? max : (val * (unsigned int)max / asrc[x] + offset);
                dst[x] = dst[x] > 0 ? dst[x] : 0;
            } else {
                dst[x] = msrc[x];
            }
        }
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
