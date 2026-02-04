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
    uint16_t acc = 0;
    for (i = 0; i < h; i++) {
        acc += scale * src[0] + dc;
        dst[0] = acc;
        if (scale)
            src += stride;
        dst += stride;
    }
}
