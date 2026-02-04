#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *top;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses every second element first, then the odd indices
    for (i = 0; i < bpp; i += 2) {
        dst[i] = src[i] - (top[i] >> 1);
    }
    for (i = 1; i < bpp; i += 2) {
        dst[i] = src[i] - (top[i] >> 1);
    }
}
