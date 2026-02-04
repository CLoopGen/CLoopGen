#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (dsize = 0; dsize < size; dsize += 2) {
        *dst++ = src[dsize];
        if (dsize + 1 < size) {
            *dst++ = src[dsize + 1];
        }
    }
}
