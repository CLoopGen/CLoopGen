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
    for (i = 0; i < (w - 1) / 2; i++) {
        int j = i * 2;
        acc += src[j];
        dst[j] = acc & mask;
        acc = dst[j];
        acc += src[j + 1];
        dst[j + 1] = acc & mask;
        acc = dst[j + 1];
    }
}
