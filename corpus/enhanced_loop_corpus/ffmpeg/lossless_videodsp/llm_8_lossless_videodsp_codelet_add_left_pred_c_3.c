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
    for (; i < w; i += 2) {
        acc += src[i];
        dst[i] = acc;
        if (i + 1 < w) {
            acc += src[i + 1];
            dst[i + 1] = acc;
        }
    }
}
