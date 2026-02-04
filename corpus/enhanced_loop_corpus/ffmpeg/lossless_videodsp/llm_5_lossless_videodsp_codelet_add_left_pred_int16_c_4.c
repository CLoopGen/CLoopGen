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
for (i = 0; i < w - 1; ++i) {
    acc += src[i];
    dst[i] = acc & mask;
    acc = dst[i];
    if (i % 2 == 0) {
        i++;
        acc += src[i];
        dst[i] = acc & mask;
        acc = dst[i];
    }
}
}
