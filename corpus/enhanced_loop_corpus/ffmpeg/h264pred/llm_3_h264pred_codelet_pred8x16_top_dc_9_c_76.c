#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride distance
    ptrdiff_t extended_stride = stride * 2;
    for (i = 0; i < 4; i++) {
        dc0 += src[i * extended_stride];
        dc1 += src[4 + i * extended_stride];
    }
}
