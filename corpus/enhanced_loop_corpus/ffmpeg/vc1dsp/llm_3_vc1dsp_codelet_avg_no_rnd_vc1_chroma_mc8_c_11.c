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
for (i = 0; i < h; i++) {
    ptrdiff_t offset;
    // Access memory in a strided pattern across multiple rows, unrolling by reordering access
    offset = 0 * stride;
    dst[offset + 0] = (((dst[offset + 0]) + (((A * src[offset + 0] + B * src[offset + 1] + C * src[offset + stride + 0] + D * src[offset + stride + 1] + 32 - 4) >> 6)) + 1) >> 1);
    dst[offset + 1] = (((dst[offset + 1]) + (((A * src[offset + 1] + B * src[offset + 2] + C * src[offset + stride + 1] + D * src[offset + stride + 2] + 32 - 4) >> 6)) + 1) >> 1);

    offset = 1 * stride;
    dst[offset + 0] = (((dst[offset + 0]) + (((A * src[offset + 0] + B * src[offset + 1] + C * src[offset + stride + 0] + D * src[offset + stride + 1] + 32 - 4) >> 6)) + 1) >> 1);
    dst[offset + 1] = (((dst[offset + 1]) + (((A * src[offset + 1] + B * src[offset + 2] + C * src[offset + stride + 1] + D * src[offset + stride + 2] + 32 - 4) >> 6)) + 1) >> 1);

    offset = 2 * stride;
    dst[offset + 0] = (((dst[offset + 0]) + (((A * src[offset + 0] + B * src[offset + 1] + C * src[offset + stride + 0] + D * src[offset + stride + 1] + 32 - 4) >> 6)) + 1) >> 1);
    dst[offset + 1] = (((dst[offset + 1]) + (((A * src[offset + 1] + B * src[offset + 2] + C * src[offset + stride + 1] + D * src[offset + stride + 2] + 32 - 4) >> 6)) + 1) >> 1);

    offset = 3 * stride;
    dst[offset + 0] = (((dst[offset + 0]) + (((A * src[offset + 0] + B * src[offset + 1] + C * src[offset + stride + 0] + D * src[offset + stride + 1] + 32 - 4) >> 6)) + 1) >> 1);
    dst[offset + 1] = (((dst[offset + 1]) + (((A * src[offset + 1] + B * src[offset + 2] + C * src[offset + stride + 1] + D * src[offset + stride + 2] + 32 - 4) >> 6)) + 1) >> 1);

    // Update pointers once per full row
    dst += 4 * stride;
    src += 4 * stride;
    i += 3; // Adjust loop counter since we process 4 rows per iteration
}
}
