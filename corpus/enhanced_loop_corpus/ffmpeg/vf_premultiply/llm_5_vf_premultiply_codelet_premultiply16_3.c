#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int half;
extern int shift;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int modulated = asrc[x];
        int control = (modulated >> 1) & 1;
        dst[x] = 0;
        if (modulated > 10) {
            dst[x] = ((msrc[x] * (control + modulated)) + half) >> shift;
        } else if (modulated > 0 && modulated <= 10) {
            dst[x] = (msrc[x] + half) >> shift;
        }
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
