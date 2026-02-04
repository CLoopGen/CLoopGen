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
    // Variant 2: Indirect memory access via precomputed index array
    static ptrdiff_t indices[16];
    if (indices[0] == 0) { // Initialize indices once
        for (int j = 0; j < 16; j++) {
            indices[j] = -1 + j * stride;
        }
    }
    for (i = 0; i < 16; i++) {
        dc += src[indices[i]];
    }
}
