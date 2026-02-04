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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t offset = i * stride;
    dst[offset + 0] = (((dst[offset + 0]) + (((A * src[offset + 0]) + 32) >> 6) + 1) >> 1);
    dst[offset + 1] = (((dst[offset + 1]) + (((A * src[offset + 1]) + 32) >> 6) + 1) >> 1);
    dst[offset + 2] = (((dst[offset + 2]) + (((A * src[offset + 2]) + 32) >> 6) + 1) >> 1);
    dst[offset + 3] = (((dst[offset + 3]) + (((A * src[offset + 3]) + 32) >> 6) + 1) >> 1);
    dst[offset + 4] = (((dst[offset + 4]) + (((A * src[offset + 4]) + 32) >> 6) + 1) >> 1);
    dst[offset + 5] = (((dst[offset + 5]) + (((A * src[offset + 5]) + 32) >> 6) + 1) >> 1);
    dst[offset + 6] = (((dst[offset + 6]) + (((A * src[offset + 6]) + 32) >> 6) + 1) >> 1);
    dst[offset + 7] = (((dst[offset + 7]) + (((A * src[offset + 7]) + 32) >> 6) + 1) >> 1);
}
}
