#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride step (stride * 2) to create a more scattered access pattern
    ptrdiff_t effective_stride = stride * 2;
    for (i = 0; i < 16; i++) {
        dc += src[i * effective_stride];
    }
}
