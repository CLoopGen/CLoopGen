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
for (i = 0; i < h; i += 2) {
    int offset1 = 0;
    int offset2 = stride;
    dst[offset1 + 0] = ((((A * src[offset1 + 0] + B * src[offset1 + 1] + C * src[offset2 + 0] + D * src[offset2 + 1]) + 32) >> 6));
    dst[offset1 + 1] = ((((A * src[offset1 + 1] + B * src[offset1 + 2] + C * src[offset2 + 1] + D * src[offset2 + 2]) + 32) >> 6));
    dst[offset1 + 2] = ((((A * src[offset1 + 2] + B * src[offset1 + 3] + C * src[offset2 + 2] + D * src[offset2 + 3]) + 32) >> 6));
    dst[offset1 + 3] = ((((A * src[offset1 + 3] + B * src[offset1 + 4] + C * src[offset2 + 3] + D * src[offset2 + 4]) + 32) >> 6));
    dst[offset1 + 4] = ((((A * src[offset1 + 4] + B * src[offset1 + 5] + C * src[offset2 + 4] + D * src[offset2 + 5]) + 32) >> 6));
    dst[offset1 + 5] = ((((A * src[offset1 + 5] + B * src[offset1 + 6] + C * src[offset2 + 5] + D * src[offset2 + 6]) + 32) >> 6));
    dst[offset1 + 6] = ((((A * src[offset1 + 6] + B * src[offset1 + 7] + C * src[offset2 + 6] + D * src[offset2 + 7]) + 32) >> 6));
    dst[offset1 + 7] = ((((A * src[offset1 + 7] + B * src[offset1 + 8] + C * src[offset2 + 7] + D * src[offset2 + 8]) + 32) >> 6));

    if (i + 1 < h) {
        dst += stride;
        src += stride;
        offset1 = 0;
        offset2 = stride;
        dst[offset1 + 0] = ((((A * src[offset1 + 0] + B * src[offset1 + 1] + C * src[offset2 + 0] + D * src[offset2 + 1]) + 32) >> 6));
        dst[offset1 + 1] = ((((A * src[offset1 + 1] + B * src[offset1 + 2] + C * src[offset2 + 1] + D * src[offset2 + 2]) + 32) >> 6));
        dst[offset1 + 2] = ((((A * src[offset1 + 2] + B * src[offset1 + 3] + C * src[offset2 + 2] + D * src[offset2 + 3]) + 32) >> 6));
        dst[offset1 + 3] = ((((A * src[offset1 + 3] + B * src[offset1 + 4] + C * src[offset2 + 3] + D * src[offset2 + 4]) + 32) >> 6));
        dst[offset1 + 4] = ((((A * src[offset1 + 4] + B * src[offset1 + 5] + C * src[offset2 + 4] + D * src[offset2 + 5]) + 32) >> 6));
        dst[offset1 + 5] = ((((A * src[offset1 + 5] + B * src[offset1 + 6] + C * src[offset2 + 5] + D * src[offset2 + 6]) + 32) >> 6));
        dst[offset1 + 6] = ((((A * src[offset1 + 6] + B * src[offset1 + 7] + C * src[offset2 + 6] + D * src[offset2 + 7]) + 32) >> 6));
        dst[offset1 + 7] = ((((A * src[offset1 + 7] + B * src[offset1 + 8] + C * src[offset2 + 7] + D * src[offset2 + 8]) + 32) >> 6));
    }
    dst += stride;
    src += stride;
}
}
