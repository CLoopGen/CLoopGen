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
    ptrdiff_t offset;
    for (i = 0; i < h; i++) {
        offset = i * stride;
        dst[offset + 0] = (((dst[offset + 0]) + (((A * src[offset + 0] + E * src[offset + step + 0] + bias)) >> 6) + 1) >> 1);
        dst[offset + 1] = (((dst[offset + 1]) + (((A * src[offset + 1] + E * src[offset + step + 1] + bias)) >> 6) + 1) >> 1);
        dst[offset + 2] = (((dst[offset + 2]) + (((A * src[offset + 2] + E * src[offset + step + 2] + bias)) >> 6) + 1) >> 1);
        dst[offset + 3] = (((dst[offset + 3]) + (((A * src[offset + 3] + E * src[offset + step + 3] + bias)) >> 6) + 1) >> 1);
        dst[offset + 4] = (((dst[offset + 4]) + (((A * src[offset + 4] + E * src[offset + step + 4] + bias)) >> 6) + 1) >> 1);
        dst[offset + 5] = (((dst[offset + 5]) + (((A * src[offset + 5] + E * src[offset + step + 5] + bias)) >> 6) + 1) >> 1);
        dst[offset + 6] = (((dst[offset + 6]) + (((A * src[offset + 6] + E * src[offset + step + 6] + bias)) >> 6) + 1) >> 1);
        dst[offset + 7] = (((dst[offset + 7]) + (((A * src[offset + 7] + E * src[offset + step + 7] + bias)) >> 6) + 1) >> 1);
    }
}
