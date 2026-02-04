#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern int h;
extern int stride;
extern int scale;
extern unsigned int dc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer;
    for (outer = 0; outer < h; outer++) {
        dst[0] = scale * src[0] + dc;
        if (scale)
            src += stride;
        dst += stride;
    }
}
