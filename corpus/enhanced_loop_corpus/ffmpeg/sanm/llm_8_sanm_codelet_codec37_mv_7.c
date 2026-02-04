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
for (j = 0; j < 8; j++) {
    for (i = 0; i < 4; i++) {
        int addr = pos + i;
        if (addr < 0 || addr >= height * stride)
            dst[i] = 0;
        else
            dst[i] = src[i];
    }
    dst += stride;
    src += stride;
    pos += stride;
}
}
