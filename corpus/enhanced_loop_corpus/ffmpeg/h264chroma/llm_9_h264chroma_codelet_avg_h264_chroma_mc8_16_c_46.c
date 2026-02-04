#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        // Unroll two iterations
        // First iteration
        dst[0] = ((dst[0] + ((A * src[0] + E * src[step + 0] + 32) >> 6) + 1) >> 1);
        dst[1] = ((dst[1] + ((A * src[1] + E * src[step + 1] + 32) >> 6) + 1) >> 1);
        dst[2] = ((dst[2] + ((A * src[2] + E * src[step + 2] + 32) >> 6) + 1) >> 1);
        dst[3] = ((dst[3] + ((A * src[3] + E * src[step + 3] + 32) >> 6) + 1) >> 1);
        dst[4] = ((dst[4] + ((A * src[4] + E * src[step + 4] + 32) >> 6) + 1) >> 1);
        dst[5] = ((dst[5] + ((A * src[5] + E * src[step + 5] + 32) >> 6) + 1) >> 1);
        dst[6] = ((dst[6] + ((A * src[6] + E * src[step + 6] + 32) >> 6) + 1) >> 1);
        dst[7] = ((dst[7] + ((A * src[7] + E * src[step + 7] + 32) >> 6) + 1) >> 1);

        ptrdiff_t dst_offset1 = stride;
        ptrdiff_t src_offset1 = stride;

        // Second iteration
        uint16_t* dst2 = dst + dst_offset1;
        uint16_t* src2 = src + src_offset1;
        dst2[0] = ((dst2[0] + ((A * src2[0] + E * src2[step + 0] + 32) >> 6) + 1) >> 1);
        dst2[1] = ((dst2[1] + ((A * src2[1] + E * src2[step + 1] + 32) >> 6) + 1) >> 1);
        dst2[2] = ((dst2[2] + ((A * src2[2] + E * src2[step + 2] + 32) >> 6) + 1) >> 1);
        dst2[3] = ((dst2[3] + ((A * src2[3] + E * src2[step + 3] + 32) >> 6) + 1) >> 1);
        dst2[4] = ((dst2[4] + ((A * src2[4] + E * src2[step + 4] + 32) >> 6) + 1) >> 1);
        dst2[5] = ((dst2[5] + ((A * src2[5] + E * src2[step + 5] + 32) >> 6) + 1) >> 1);
        dst2[6] = ((dst2[6] + ((A * src2[6] + E * src2[step + 6] + 32) >> 6) + 1) >> 1);
        dst2[7] = ((dst2[7] + ((A * src2[7] + E * src2[step + 7] + 32) >> 6) + 1) >> 1);

        dst += 2 * stride;
        src += 2 * stride;
    } else {
        // Handle odd h: single iteration
        dst[0] = ((dst[0] + ((A * src[0] + E * src[step + 0] + 32) >> 6) + 1) >> 1);
        dst[1] = ((dst[1] + ((A * src[1] + E * src[step + 1] + 32) >> 6) + 1) >> 1);
        dst[2] = ((dst[2] + ((A * src[2] + E * src[step + 2] + 32) >> 6) + 1) >> 1);
        dst[3] = ((dst[3] + ((A * src[3] + E * src[step + 3] + 32) >> 6) + 1) >> 1);
        dst[4] = ((dst[4] + ((A * src[4] + E * src[step + 4] + 32) >> 6) + 1) >> 1);
        dst[5] = ((dst[5] + ((A * src[5] + E * src[step + 5] + 32) >> 6) + 1) >> 1);
        dst[6] = ((dst[6] + ((A * src[6] + E * src[step + 6] + 32) >> 6) + 1) >> 1);
        dst[7] = ((dst[7] + ((A * src[7] + E * src[step + 7] + 32) >> 6) + 1) >> 1);
        dst += stride;
        src += stride;
    }
}
}
