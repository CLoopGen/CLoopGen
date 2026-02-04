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
    uint8_t temp_val;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            temp_val = osrc[x] - bsrc[x];
            dst[x] = bsrc[x] + ((msrc[x] * temp_val + 128) >> 8);
        }
        dst += dlinesize;
        bsrc += blinesize;
        osrc += olinesize;
        msrc += mlinesize;
    }
}
