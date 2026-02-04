#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (stride of 2, then process both elements)
    for (i = 0; i < size; i += 2, src += 2) {
        if (i + 1 < size && src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && (i + 1) < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            // Simulate skip by not processing next element in pair
            if (i + 2 < size) {
                // Handle overlap: next iteration skips automatically due to i += 2
            }
        } else {
            // Process current and next element sequentially if safe
            dst[dsize++] = *src;
            if (i + 1 < size) {
                dst[dsize++] = src[1];
            }
        }
    }
}
