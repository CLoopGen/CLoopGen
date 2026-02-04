#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern int i;
extern int bias;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    int offset1 = 0, offset2 = 8;
    dst[offset1 + 0] = (((A * src[offset1 + 0] + E * src[step + offset1 + 0] + bias)) >> 6);
    dst[offset1 + 1] = (((A * src[offset1 + 1] + E * src[step + offset1 + 1] + bias)) >> 6);
    dst[offset1 + 2] = (((A * src[offset1 + 2] + E * src[step + offset1 + 2] + bias)) >> 6);
    dst[offset1 + 3] = (((A * src[offset1 + 3] + E * src[step + offset1 + 3] + bias)) >> 6);
    dst[offset1 + 4] = (((A * src[offset1 + 4] + E * src[step + offset1 + 4] + bias)) >> 6);
    dst[offset1 + 5] = (((A * src[offset1 + 5] + E * src[step + offset1 + 5] + bias)) >> 6);
    dst[offset1 + 6] = (((A * src[offset1 + 6] + E * src[step + offset1 + 6] + bias)) >> 6);
    dst[offset1 + 7] = (((A * src[offset1 + 7] + E * src[step + offset1 + 7] + bias)) >> 6);

    if (i + 1 < h) {
        dst[offset2 + 0] = (((A * src[stride + offset2 - 8 + 0] + E * src[stride + step + offset2 - 8 + 0] + bias)) >> 6);
        dst[offset2 + 1] = (((A * src[stride + offset2 - 8 + 1] + E * src[stride + step + offset2 - 8 + 1] + bias)) >> 6);
        dst[offset2 + 2] = (((A * src[stride + offset2 - 8 + 2] + E * src[stride + step + offset2 - 8 + 2] + bias)) >> 6);
        dst[offset2 + 3] = (((A * src[stride + offset2 - 8 + 3] + E * src[stride + step + offset2 - 8 + 3] + bias)) >> 6);
        dst[offset2 + 4] = (((A * src[stride + offset2 - 8 + 4] + E * src[stride + step + offset2 - 8 + 4] + bias)) >> 6);
        dst[offset2 + 5] = (((A * src[stride + offset2 - 8 + 5] + E * src[stride + step + offset2 - 8 + 5] + bias)) >> 6);
        dst[offset2 + 6] = (((A * src[stride + offset2 - 8 + 6] + E * src[stride + step + offset2 - 8 + 6] + bias)) >> 6);
        dst[offset2 + 7] = (((A * src[stride + offset2 - 8 + 7] + E * src[stride + step + offset2 - 8 + 7] + bias)) >> 6);
    }
    dst += 2 * stride;
    src += 2 * stride;
}
}
