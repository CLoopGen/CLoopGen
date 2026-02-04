#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    int offset1 = 0, offset2 = stride;
    // Process two rows per iteration to increase computational intensity
    for (int j = 0; j < 8; j++) {
        dst[offset1 + j] = (((dst[offset1 + j]) + (((A * src[offset1 + j] + B * src[offset1 + j + 1] +
                             C * src[offset2 + j] + D * src[offset2 + j + 1] + 28) >> 6)) + 1) >> 1);
        if (i + 1 < h) {
            dst[offset2 + j] = (((dst[offset2 + j]) + (((A * src[offset2 + j] + B * src[offset2 + j + 1] +
                                 C * src[stride + offset2 + j] + D * src[stride + offset2 + j + 1] + 28) >> 6)) + 1) >> 1);
        }
    }
    dst += 2 * stride;
    src += 2 * stride;
}
}
