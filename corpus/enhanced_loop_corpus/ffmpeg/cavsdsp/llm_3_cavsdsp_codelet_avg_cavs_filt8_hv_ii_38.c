#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src2;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided access with step size of 2 (simulating non-unit stride traversal)
    for (i = 0; i < w; i++) {
        // Access tmp with a fixed offset base, but step through it in larger increments externally
        const int idx = 8 * (i % 4); // simulate irregular but bounded access pattern

        const int tmpB = tmp[idx - 2 * 8];
        const int tmpA = tmp[idx - 1 * 8];
        const int tmp0 = tmp[idx + 0 * 8];
        const int tmp1 = tmp[idx + 1 * 8];
        const int tmp2 = tmp[idx + 2 * 8];
        const int tmp3 = tmp[idx + 3 * 8];
        const int tmp4 = tmp[idx + 4 * 8];
        const int tmp5 = tmp[idx + 5 * 8];
        const int tmp6 = tmp[idx + 6 * 8];
        const int tmp7 = tmp[idx + 7 * 8];
        const int tmp8 = tmp[idx + 8 * 8];
        const int tmp9 = tmp[idx + 9 * 8];
        const int tmp10 = tmp[idx + 10 * 8];

        // Strided write and read using varying offsets derived from i
        const ptrdiff_t di = (i & 1) ? 2 : 1; // Alternate stride for dst
        const ptrdiff_t si = (i & 2) ? 3 : 1; // Alternate stride for src2

        dst[0 * di * dstStride] = ((dst[0 * di * dstStride]) + cm[((-tmpA + 5 * tmp0 + 5 * tmp1 - tmp2 + 64 * src2[0 * si * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[1 * di * dstStride] = ((dst[1 * di * dstStride]) + cm[((-tmp0 + 5 * tmp1 + 5 * tmp2 - tmp3 + 64 * src2[1 * si * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[2 * di * dstStride] = ((dst[2 * di * dstStride]) + cm[((-tmp1 + 5 * tmp2 + 5 * tmp3 - tmp4 + 64 * src2[2 * si * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[3 * di * dstStride] = ((dst[3 * di * dstStride]) + cm[((-tmp2 + 5 * tmp3 + 5 * tmp4 - tmp5 + 64 * src2[3 * si * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[4 * di * dstStride] = ((dst[4 * di * dstStride]) + cm[((-tmp3 + 5 * tmp4 + 5 * tmp5 - tmp6 + 64 * src2[4 * si * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[5 * di * dstStride] = ((dst[5 * di * dstStride]) + cm[((-tmp4 + 5 * tmp5 + 5 * tmp6 - tmp7 + 64 * src2[5 * si * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[6 * di * dstStride] = ((dst[6 * di * dstStride]) + cm[((-tmp5 + 5 * tmp6 + 5 * tmp7 - tmp8 + 64 * src2[6 * si * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[7 * di * dstStride] = ((dst[7 * di * dstStride]) + cm[((-tmp6 + 5 * tmp7 + 5 * tmp8 - tmp9 + 64 * src2[7 * si * srcStride]) + 512) >> 10] + 1) >> 1;

        // Update pointers with variable step depending on iteration
        dst += (i % 3 == 0) ? 2 : 1;
        tmp += (i % 3 == 0) ? 2 : 1;
        src2 += (i % 3 == 0) ? 2 : 1;
    }
}
