#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint32_t *src;
extern uint32_t *dst;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= w; j++) {
        dst[w - j] = src[-(w - j)];
    }
}
