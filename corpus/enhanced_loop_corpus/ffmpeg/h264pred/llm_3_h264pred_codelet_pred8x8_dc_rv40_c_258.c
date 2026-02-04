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
    // Variant 2: Strided access across multiple rows with increased stride in memory layout
    // Simulate a wider stride effect by accessing every other row in a blocked pattern
    ptrdiff_t effective_stride = stride * 2; // Access every second row
    for (i = 2; i < 6; i++) {
        ((uint32_t *)(src + (2*i) * stride))[0] = dc0;
        ((uint32_t *)(src + (2*i) * stride))[1] = dc0;
    }
}
