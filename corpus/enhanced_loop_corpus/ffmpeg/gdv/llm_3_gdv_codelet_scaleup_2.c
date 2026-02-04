#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride on source
    // Instead of reading every (x>>1), we introduce a fixed stride pattern to increase cache line utilization
    int stride = 2;
    for (; x < w; x++) {
        int index = (x / 2) * stride; // maps to strided access in src
        dst[x] = src[index % w];      // ensure within bounds using modulo
    }
}
