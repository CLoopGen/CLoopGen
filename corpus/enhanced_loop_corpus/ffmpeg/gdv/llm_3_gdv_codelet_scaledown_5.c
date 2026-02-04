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
    // Variant 2: Strided Access with Fixed Step in src, Unrolled Differently
    // Modify access pattern to use a fixed stride variable and simulate a more regular strided pattern
    // This variant emphasizes predictable memory access for potential vectorization
    for (x = 0; x < w - 7; x += 8) {
        int i;
        for (i = 0; i < 8; i++) {
            dst[x + i] = src[2 * (x + i)];
        }
    }
}
