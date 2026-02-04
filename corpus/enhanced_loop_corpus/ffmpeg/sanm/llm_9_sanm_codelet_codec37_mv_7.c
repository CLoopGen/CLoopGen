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
for (j = 0; j < 2; j++) {
    for (i = 0; i < 8; i += 2) {
        int p1 = pos + i;
        int p2 = pos + i + 1;
        if (p1 >= 0 && p1 < height * stride)
            dst[i] = src[i];
        else
            dst[i] = 0;
        if (p2 >= 0 && p2 < height * stride)
            dst[i + 1] = src[i + 1];
        else
            dst[i + 1] = 0;
    }
    dst += stride * 2;
    src += stride * 2;
    pos += stride * 2;
}
}
