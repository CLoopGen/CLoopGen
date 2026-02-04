#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with forward stepping by 2
    for (; i < size; i += 2) {
        if (i - bpp >= 0) {
            dst[i] = ((dst[i - bpp]) + (src[i]));
        }
        if (i + 1 < size && (i + 1 - bpp) >= 0) {
            dst[i + 1] = ((dst[i + 1 - bpp]) + (src[i + 1]));
        }
    }
}
