#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride step (every 2nd element backwards)
    // Access elements at positions: -stride*1, -stride*3, -stride*5, ..., skipping every other stride
    for (i = 0; i < 16; i++) {
        dc += src[i * 2 - stride];
    }
}
