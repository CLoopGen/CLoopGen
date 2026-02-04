#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < w; i++) {
        uint16_t temp = dst[i] + src[i];
        if ((temp & mask) != 0)
            dst[i] = temp & mask;
    }
}
