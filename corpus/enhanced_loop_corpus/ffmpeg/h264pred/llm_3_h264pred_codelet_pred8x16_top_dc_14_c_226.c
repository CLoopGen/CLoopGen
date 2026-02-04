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
    // Variant 2: Strided access with increased stride step
    // Access elements using a doubled stride for a more scattered memory pattern
    ptrdiff_t effective_stride = 2 * stride;
    for (i = 0; i < 4; i++) {
        dc0 += src[i * effective_stride];
        dc1 += src[4 * effective_stride + i * effective_stride];
    }
}
