#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int srcHeight;
extern int srcStride;
extern int dstStride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < srcHeight; y++) {
    const int mmxSize = 1;
    uint8_t *src_row0 = &src[y * srcStride];
    uint8_t *src_row1 = &src[(y - 1) * srcStride];
    uint8_t *dst_ptr = &dst[(y - 1) * dstStride * 2];

    dst_ptr[0] = (src_row1[0] * 3 + src_row0[0]) >> 2;
    dst_ptr[dstStride] = (src_row1[0] + 3 * src_row0[0]) >> 2;

    for (x = mmxSize - 1; x < srcWidth - 1; x++) {
        dst_ptr[2 * x + 1] = (src_row1[x] * 3 + src_row0[x + 1]) >> 2;
        dst_ptr[2 * x + dstStride + 2] = (src_row1[x] + 3 * src_row0[x + 1]) >> 2;
        dst_ptr[2 * x + dstStride + 1] = (src_row1[x + 1] + 3 * src_row0[x]) >> 2;
        dst_ptr[2 * x + 2] = (src_row1[x + 1] * 3 + src_row0[x]) >> 2;
    }

    int last = srcWidth - 1;
    dst_ptr[srcWidth * 2 - 1] = (src_row1[last] * 3 + src_row0[last]) >> 2;
    dst_ptr[srcWidth * 2 - 1 + dstStride] = (src_row1[last] + 3 * src_row0[last]) >> 2;
}
}
