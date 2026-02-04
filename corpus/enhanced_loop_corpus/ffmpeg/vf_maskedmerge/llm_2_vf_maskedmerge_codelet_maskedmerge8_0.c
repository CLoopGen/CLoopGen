#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bsrc;
extern  uint8_t *osrc;
extern  uint8_t *msrc;
extern uint8_t *dst;
extern ptrdiff_t blinesize;
extern ptrdiff_t olinesize;
extern ptrdiff_t mlinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w - 3; x += 4) {
        dst[x]   = bsrc[x]   + ((msrc[x]   * (osrc[x]   - bsrc[x])   + 128) >> 8);
        dst[x+1] = bsrc[x+1] + ((msrc[x+1] * (osrc[x+1] - bsrc[x+1]) + 128) >> 8);
        dst[x+2] = bsrc[x+2] + ((msrc[x+2] * (osrc[x+2] - bsrc[x+2]) + 128) >> 8);
        dst[x+3] = bsrc[x+3] + ((msrc[x+3] * (osrc[x+3] - bsrc[x+3]) + 128) >> 8);
    }
    for (; x < w; x++) {
        dst[x] = bsrc[x] + ((msrc[x] * (osrc[x] - bsrc[x]) + 128) >> 8);
    }
    dst += dlinesize;
    bsrc += blinesize;
    osrc += olinesize;
    msrc += mlinesize;
}
}
