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
    // Variant 2: Strided memory access with increased step in indexing
    // Access every second element over a wider range using positive and negative offset
    ptrdiff_t idx = -stride;
    for (i = 0; i < 16; i++, idx += 2) {
        dc += src[idx];
    }
}
