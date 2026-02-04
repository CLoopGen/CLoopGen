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
for (i = 0; i < h; i++) {
    if (scale == 0) {
        dst[0] = dc;
    } else {
        dst[0] = scale * src[0] + dc;
        src += stride;
    }
    dst += stride;
}
}
