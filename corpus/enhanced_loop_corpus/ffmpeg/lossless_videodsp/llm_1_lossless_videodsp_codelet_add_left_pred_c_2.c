#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t w;
extern int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (w - 1) / 2; i++) {
        int j = i * 2;
        acc += src[j];
        dst[j] = acc;
        acc += src[j + 1];
        dst[j + 1] = acc;
    }
    if ((w - 1) % 2 == 1) {
        acc += src[w - 2];
        dst[w - 2] = acc;
    }
}
