#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h > 0) {
        for (i = 0; i < h; i += 2) {
            // First iteration of unrolled loop body
            dst[0] = (((dst[0]) + ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6) + 1) >> 1);
            dst += stride;
            src += stride;

            // Second iteration, if within bounds
            if (i + 1 < h) {
                dst[0] = (((dst[0]) + ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6) + 1) >> 1);
                dst += stride;
                src += stride;
            }
        }
    }
}
