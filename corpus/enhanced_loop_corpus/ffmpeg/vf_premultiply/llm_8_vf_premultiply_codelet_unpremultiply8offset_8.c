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
extern int offset;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 2) {
        uint8_t avg_m = (msrc[x] + msrc[(x+1) < w ? x+1 : x]) / 2;
        uint8_t avg_a = (asrc[x] + asrc[(x+1) < w ? x+1 : x]) / 2;
        uint8_t base = (avg_m - offset) > 0 ? (avg_m - offset) : 0;
        uint8_t result = (base * 255 / (avg_a > 0 ? avg_a : 1) + offset);
        dst[x] = result > 255 ? 255 : result;
        if (x + 1 < w) {
            dst[x + 1] = dst[x];
        }
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
