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
        // Process two iterations at once to increase computational intensity
        uint8_t *dst1 = dst;
        uint8_t *dst2 = dst + stride;
        uint8_t *src1 = src;
        uint8_t *src2 = src + stride;

        dst1[0] = (((dst1[0]) + ((((A * src1[0] + E * src1[step + 0])) + 32) >> 6) + 1) >> 1);
        dst1[1] = (((dst1[1]) + ((((A * src1[1] + E * src1[step + 1])) + 32) >> 6) + 1) >> 1);
        dst1[2] = (((dst1[2]) + ((((A * src1[2] + E * src1[step + 2])) + 32) >> 6) + 1) >> 1);
        dst1[3] = (((dst1[3]) + ((((A * src1[3] + E * src1[step + 3])) + 32) >> 6) + 1) >> 1);

        dst2[0] = (((dst2[0]) + ((((A * src2[0] + E * src2[step + 0])) + 32) >> 6) + 1) >> 1);
        dst2[1] = (((dst2[1]) + ((((A * src2[1] + E * src2[step + 1])) + 32) >> 6) + 1) >> 1);
        dst2[2] = (((dst2[2]) + ((((A * src2[2] + E * src2[step + 2])) + 32) >> 6) + 1) >> 1);
        dst2[3] = (((dst2[3]) + ((((A * src2[3] + E * src2[step + 3])) + 32) >> 6) + 1) >> 1);

        dst += 2 * stride;
        src += 2 * stride;
    } else {
        // Handle remaining iteration if h is odd
        dst[0] = (((dst[0]) + ((((A * src[0] + E * src[step + 0])) + 32) >> 6) + 1) >> 1);
        dst[1] = (((dst[1]) + ((((A * src[1] + E * src[step + 1])) + 32) >> 6) + 1) >> 1);
        dst[2] = (((dst[2]) + ((((A * src[2] + E * src[step + 2])) + 32) >> 6) + 1) >> 1);
        dst[3] = (((dst[3]) + ((((A * src[3] + E * src[step + 3])) + 32) >> 6) + 1) >> 1);
        dst += stride;
        src += stride;
    }
}
}
