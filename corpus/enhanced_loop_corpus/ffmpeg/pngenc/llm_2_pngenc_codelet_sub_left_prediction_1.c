#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int x;
extern int unaligned_w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses every second element in src1 and src2, reducing the effective iteration count by half
    int stride = 2;
    int limit = unaligned_w / stride;
    for (x = 0; x < limit; x++) {
        *dst++ = src1[x * stride] - src2[x * stride];
    }
}
