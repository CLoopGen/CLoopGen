#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int w;
extern int h;
extern int color;
extern int stride;
extern int i;
extern int j;
extern uint32_t *dst2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (reverse traversal with stride of 2, then fill in odd indices)
    for (j = 0; j < h; j++) {
        dst2 = (uint32_t *)dst;
        // First pass: write to even indices in reverse order (strided access)
        for (i = (w % 2 == 0 ? w - 2 : w - 1); i >= 0; i -= 2) {
            dst2[i] = color;
        }
        // Second pass: write to odd indices forward
        for (i = 1; i < w; i += 2) {
            dst2[i] = color;
        }
        dst += stride;
    }
}
