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
    // Variant 2: Indirect memory access via index array
    // Use a lookup table of offsets to simulate irregular or indirect access pattern
    static const int offsets[8] = {0, 2, 4, 6, 8, 10, 12, 14}; // Example non-unit strides
    dc0 = 0;
    for (i = 0; i < 8; i++) {
        dc0 += src[-1 + offsets[i]];
    }
}
