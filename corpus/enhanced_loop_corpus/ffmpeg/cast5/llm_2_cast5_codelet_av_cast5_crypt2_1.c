#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern uint8_t *iv;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to maintain 8 effective operations
    int stride = 2;
    for (i = 0; i < 16; i += stride)
        dst[i / 2] = src[i] ^ iv[i];
}
