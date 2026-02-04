#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in forward order
    int stride = 2;
    for (i = 0; i < size; i += stride) {
        dst[i] = ((((src[i]) << 3) & 192) | (((src[i]) << 3) & 56) | (((src[i]) >> 5) & 7));
        if (i + 1 < size) {
            dst[i + 1] = ((((src[i + 1]) << 3) & 192) | (((src[i + 1]) << 3) & 56) | (((src[i + 1]) >> 5) & 7));
        }
    }
}
