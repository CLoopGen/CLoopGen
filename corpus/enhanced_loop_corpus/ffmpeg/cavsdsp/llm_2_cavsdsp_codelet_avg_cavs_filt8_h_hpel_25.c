#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with local blocking (unrolled by 2)
    int i;
    for (i = 0; i < h; i++) {
        uint8_t *d = dst;
        uint8_t *s = src;

        // Process two pixels at a time with direct consecutive indexing
        for (int j = 0; j < 8; j += 2) {
            int val1 = (0 * s[j - 2] + (-1) * s[j - 1] + 5 * s[j] + 5 * s[j + 1] + (-1) * s[j + 2] + 0 * s[j + 3] + 4) >> 3;
            int val2 = (0 * s[j - 1] + (-1) * s[j]     + 5 * s[j + 1] + 5 * s[j + 2] + (-1) * s[j + 3] + 0 * s[j + 4] + 4) >> 3;

            d[j]   = ((d[j])   + cm[val1] + 1) >> 1;
            d[j+1] = ((d[j+1]) + cm[val2] + 1) >> 1;
        }

        dst += dstStride;
        src += srcStride;
    }
}
