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
    uint8_t temp;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            temp = asrc[x];
            dst[x] = ((((msrc[x] - 128) * (((temp >> 1) & 1) + temp))) >> 8) + 128;
        }
        dst += dlinesize;
        msrc += mlinesize;
        asrc += alinesize;
    }
}
