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
    if (y + 1 < h) {
        for (x = 0; x < w; x++) {
            uint16_t mval1 = msrc[x], mval2 = msrc[x + mlinesize / 2];
            uint16_t aval1 = asrc[x], aval2 = asrc[x + alinesize / 2];
            uint16_t result1, result2;

            if (aval1 > 0 && aval1 < max) {
                unsigned int adj1 = mval1 > offset ? mval1 - offset : 0;
                result1 = (unsigned int)(adj1 * max / aval1 + offset);
                result1 = result1 > max ? max : result1;
                result1 = result1 > 0 ? result1 : 0;
            } else {
                result1 = mval1;
            }

            if (aval2 > 0 && aval2 < max) {
                unsigned int adj2 = mval2 > offset ? mval2 - offset : 0;
                result2 = (unsigned int)(adj2 * max / aval2 + offset);
                result2 = result2 > max ? max : result2;
                result2 = result2 > 0 ? result2 : 0;
            } else {
                result2 = mval2;
            }

            dst[x] = result1;
            dst[x + dlinesize / 2] = result2;
        }
        msrc += mlinesize;
        asrc += alinesize;
        dst += dlinesize;
    } else {
        for (x = 0; x < w; x++) {
            if (asrc[x] > 0 && asrc[x] < max) {
                unsigned int adjusted = (msrc[x] - offset) > 0 ? (msrc[x] - offset) : 0;
                dst[x] = ((adjusted * (unsigned int)max / asrc[x] + offset) > max ? max : (adjusted * (unsigned int)max / asrc[x] + offset));
            } else {
                dst[x] = msrc[x];
            }
        }
    }
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
    dst += dlinesize / 2;
}
}
