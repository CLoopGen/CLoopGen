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
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 2) {
        int idx = x;
        if (idx < w && asrc[idx] > 0 && asrc[idx] < max)
            dst[idx] = ((((((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * (unsigned int)max / asrc[idx] + offset) > (max) ? (max) : (((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * (unsigned int)max / asrc[idx] + offset))) > (0) ? (((((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * (unsigned int)max / asrc[idx] + offset) > (max) ? (max) : (((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * (unsigned int)max / asrc[idx] + offset))) : (0));
        else if (idx < w)
            dst[idx] = msrc[idx];

        idx = x + 1;
        if (idx < w && asrc[idx] > 0 && asrc[idx] < max)
            dst[idx] = ((((((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * (unsigned int)max / asrc[idx] + offset) > (max) ? (max) : (((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * (unsigned int)max / asrc[idx] + offset))) > (0) ? (((((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * (unsigned int)max / asrc[idx] + offset) > (max) ? (max) : (((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * (unsigned int)max / asrc[idx] + offset))) : (0));
        else if (idx < w)
            dst[idx] = msrc[idx];
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
