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
    // Processes every second element in a forward pass, then handles remainder
    int j;
    for (j = 0; j < bpp; j += 2) {
        if (j < bpp) dst[j] = src[j] - top[j];
        if (j + 1 < bpp) dst[j + 1] = src[j + 1] - top[j + 1];
    }
}
