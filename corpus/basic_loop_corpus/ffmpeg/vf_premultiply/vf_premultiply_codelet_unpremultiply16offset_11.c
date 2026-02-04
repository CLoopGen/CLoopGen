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
    for (x = 0; x < w; x++) {
        if (asrc[x] > 0 && asrc[x] < max)
            dst[x] = ((((((msrc[x] - offset) > (0) ? (msrc[x] - offset) : (0)) * (unsigned int)max / asrc[x] + offset) > (max) ? (max) : (((msrc[x] - offset) > (0) ? (msrc[x] - offset) : (0)) * (unsigned int)max / asrc[x] + offset))) > (0) ? (((((msrc[x] - offset) > (0) ? (msrc[x] - offset) : (0)) * (unsigned int)max / asrc[x] + offset) > (max) ? (max) : (((msrc[x] - offset) > (0) ? (msrc[x] - offset) : (0)) * (unsigned int)max / asrc[x] + offset))) : (0));
        else
            dst[x] = msrc[x];
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}

}
