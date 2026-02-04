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
    ptrdiff_t j;
    for (j = 0; j < w; j++) {
        for (i = j; i < j + 1 && i < w; i++) {
            acc += src[i];
            dst[i] = acc;
        }
    }
}
