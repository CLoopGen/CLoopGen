#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern ptrdiff_t width;
extern int height;
extern int i;
extern int j;
extern uint8_t prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every 2nd element first, then the odd positions
    for (j = 0; j < height; j++) {
        // Process even indices
        prev = src[0];  // Reset context for each row
        *dst++ = prev;  // First element encoded as absolute
        for (i = 2; i < width; i += 2) {
            uint8_t curr = src[i];
            *dst++ = curr - prev;
            prev = curr;
        }
        // Process odd indices
        if (width > 1) {
            prev = src[1];
            *dst++ = prev;  // First odd element as absolute
            for (i = 3; i < width; i += 2) {
                uint8_t curr = src[i];
                *dst++ = curr - prev;
                prev = curr;
            }
        }
        src += stride;
    }
}
