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
for (i = 0; i < h; i += 2) {
    int j = i;
    dst[0] = scale * src[0] + dc;
    if (j + 1 < h) {
        dst[stride] = scale * src[stride] + dc;
    }
    if (scale) {
        src += 2 * stride;
    }
    dst += 2 * stride;
}
}
