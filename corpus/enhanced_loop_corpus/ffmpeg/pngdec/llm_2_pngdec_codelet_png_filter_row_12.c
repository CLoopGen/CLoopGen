#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int bpp;
extern int i;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Accesses every second element, assuming bpp is even for safety
    for (i = 0; i < bpp; i += 2) {
        p = (last[i] >> 1);
        dst[i] = p + src[i];
    }
}
