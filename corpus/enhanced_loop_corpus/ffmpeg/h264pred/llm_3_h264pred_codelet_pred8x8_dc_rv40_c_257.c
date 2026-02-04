#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride step (every other row, deeper stride)
    // Access elements with a modified stride: use 2*stride to skip alternate rows
    for (i = 0; i < 4; i += 2) {
        ((uint32_t *)(src + i * stride))[0] = dc0;
        ((uint32_t *)(src + i * stride))[1] = dc0;
        if (i + 1 < 4) {
            ((uint32_t *)(src + (i + 1) * stride))[0] = dc0;
            ((uint32_t *)(src + (i + 1) * stride))[1] = dc0;
        }
    }
}
