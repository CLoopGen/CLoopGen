#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        // Process two rows per iteration
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 8; j++) {
                dst[k * stride + j] = ((((A * src[k * stride + j] + E * src[k * stride + step + j])) + 32) >> 6);
            }
        }
        dst += 2 * stride;
        src += 2 * stride;
    } else {
        // Handle last row if h is odd
        for (int j = 0; j < 8; j++) {
            dst[j] = ((((A * src[j] + E * src[step + j])) + 32) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
}
