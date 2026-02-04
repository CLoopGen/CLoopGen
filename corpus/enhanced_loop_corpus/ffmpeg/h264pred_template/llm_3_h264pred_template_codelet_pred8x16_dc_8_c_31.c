#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern int dc3;
extern int dc4;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with unified stride indexing
    // Collapse all accesses into a single strided traversal using a step of 'stride'
    // Simulate vector-like access along the stride dimension
    ptrdiff_t offset;
    for (i = 0; i < 4; i++) {
        offset = i * stride;
        dc0 += src[-1 + offset] + src[i - stride];
        dc1 += src[4 + i - stride];
        dc2 += src[-1 + offset + 4 * stride];
        dc3 += src[-1 + offset + 8 * stride];
        dc4 += src[-1 + offset + 12 * stride];
    }
}
