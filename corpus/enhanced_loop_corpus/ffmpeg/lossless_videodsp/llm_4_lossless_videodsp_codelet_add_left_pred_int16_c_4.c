#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern ptrdiff_t w;
extern unsigned int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w - 1; i += 2) {
    acc += src[i];
    if ((acc & mask) != 0) {
        dst[i] = acc & mask;
    }
    acc += src[i + 1];
    dst[i + 1] = acc & mask;
}
}
