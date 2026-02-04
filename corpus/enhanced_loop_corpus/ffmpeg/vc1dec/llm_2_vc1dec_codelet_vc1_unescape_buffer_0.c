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
    // Variant 1: Strided Memory Access (access every 2nd element in a forward pass, then handle remainder)
    int stride = 2;
    int limit = size - (size % stride);

    // First pass: strided access
    for (i = 0; i < limit; i += stride, src += stride) {
        if (src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            src++;
            i++;
        } else {
            dst[dsize++] = *src;
        }
    }

    // Second pass: handle remaining elements with unit stride
    for (; i < size; i++, src++) {
        if (src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            src++;
            i++;
        } else {
            dst[dsize++] = *src;
        }
    }
}
