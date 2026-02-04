#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with fixed step
    // Replace indexed addition with explicit pointer arithmetic and fixed stride-like stepping
    uint8_t *src0 = &src[-stride];
    uint8_t *src1 = &src[4 - stride];
    for (i = 0; i < 4; i++) {
        dc0 += *(src0 + i * 1);  // Emphasize unit stride
        dc1 += *(src1 + i * 1);
    }
}
