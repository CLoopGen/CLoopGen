#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing elements in a non-consecutive pattern
    for (i = 0; i < size; i += 2, src += 2) {
        if (i + 2 < size && src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && (i+1) < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            // Simulate skip of next element by not processing it again in next iteration
        } else {
            if (i < size) dst[dsize++] = *src;
            if (i+1 < size) dst[dsize++] = *(src+1);
        }
    }
}
