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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        uint32_t base_val = ((msrc[x] * (((asrc[x] >> 1) & 1) + asrc[x])) + 128) >> 8;
        dst[x] = (uint8_t)(base_val * 1.05);
        if (y + 1 < h) {
            uint8_t *dst_next = dst + dlinesize;
            uint8_t *msrc_next = msrc + mlinesize;
            uint8_t *asrc_next = asrc + alinesize;
            dst_next[x] = ((msrc_next[x] * (((asrc_next[x] >> 1) & 1) + asrc_next[x])) + 128) >> 8;
        }
    }
    dst += 2 * dlinesize;
    msrc += 2 * mlinesize;
    asrc += 2 * alinesize;
}
}
