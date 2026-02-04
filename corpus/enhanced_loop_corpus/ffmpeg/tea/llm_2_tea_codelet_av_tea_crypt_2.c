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
    // Variant 1: Strided memory access with stride of 2, unrolled to handle 8 elements
    int stride = 2;
    for (i = 0; i < 8; i += stride) {
        dst[i] = src[i] ^ iv[i];
        if (i + 1 < 8) {
            dst[i + 1] = src[i + 1] ^ iv[i + 1];
        }
    }
}
