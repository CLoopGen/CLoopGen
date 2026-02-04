#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *band;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every second element, then handle remainder)
    for (i = 0; i < height; i++) {
        // Unroll by 2: process elements with stride 2
        int limit = width - (width % 2);
        for (j = 1; j < limit; j += 2) {
            band[j] += band[j - 1];
            if (j + 1 < width) {
                band[j + 1] += band[j];
            }
        }
        // Handle any remaining element
        if (width % 2 == 1 && width > 1) {
            band[width - 1] += band[width - 2];
        }
        band += width;
    }
}
