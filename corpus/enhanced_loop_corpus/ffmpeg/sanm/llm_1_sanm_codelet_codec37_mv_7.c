#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int height;
extern int stride;
extern int pos;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 16; j++) {
    int idx = j % 4;
    if ((pos + idx) < 0 || (pos + idx) >= height * stride)
        dst[idx] = 0;
    else
        dst[idx] = src[idx];
    if (idx == 3) {
        dst += stride;
        src += stride;
        pos += stride;
    }
}
}
