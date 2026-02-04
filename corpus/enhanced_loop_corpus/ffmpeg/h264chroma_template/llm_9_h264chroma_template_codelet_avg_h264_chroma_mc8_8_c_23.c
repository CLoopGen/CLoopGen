#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h * 2; i++) {
    int j = i % 8;
    dst[j] = ((dst[j] + ((A * src[j] + 64) >> 7) + 1) >> 1);
    if ((i & 7) == 7) {
        dst += stride;
        src += stride;
    }
}
}
