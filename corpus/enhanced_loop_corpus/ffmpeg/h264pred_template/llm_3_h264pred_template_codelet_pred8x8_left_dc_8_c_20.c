#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with combined index arithmetic and unrolled-like pattern using offset array (simulated indirect with fixed offsets)
    ptrdiff_t offsets[4] = {0, stride, 2*stride, 3*stride};
    for (i = 0; i < 4; i++) {
        dc0 += src[-1 + offsets[i]];
        dc2 += src[-1 + offsets[i] + 4*stride];
    }
}
