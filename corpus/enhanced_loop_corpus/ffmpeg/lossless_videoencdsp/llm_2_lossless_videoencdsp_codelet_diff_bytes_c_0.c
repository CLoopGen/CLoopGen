#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern intptr_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in a forward pass, then handles remainder if width is odd
    for (; i < w; i += 2)
        dst[i + 0] = src1[i + 0] - src2[i + 0];

    // Handle the case where w is odd and the last element was skipped
    if ((w % 2) == 1 && (i - 2) == (w - 2)) {
        dst[w - 1] = src1[w - 1] - src2[w - 1];
    }
}
