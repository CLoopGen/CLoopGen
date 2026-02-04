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
    uint16_t temp;
    for (i = 0; i < h; i++) {
        temp = src[0];
        dst[0] = scale * temp + dc;
        if (scale)
            src += stride;
        dst += stride;
    }
}
