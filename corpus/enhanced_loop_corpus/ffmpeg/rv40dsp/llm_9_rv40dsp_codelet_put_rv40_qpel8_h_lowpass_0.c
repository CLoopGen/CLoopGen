#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int h;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        // Unroll two iterations for higher computational intensity
        const int base_shift = (1 << (SHIFT - 1));

        // First iteration
        dst[0] = cm[(src[-2] + src[3] - 5*(src[-1] + src[2]) + src[0]*C1 + src[1]*C2 + base_shift) >> SHIFT];
        dst[1] = cm[(src[-1] + src[4] - 5*(src[0] + src[3]) + src[1]*C1 + src[2]*C2 + base_shift) >> SHIFT];
        dst[2] = cm[(src[0] + src[5] - 5*(src[1] + src[4]) + src[2]*C1 + src[3]*C2 + base_shift) >> SHIFT];
        dst[3] = cm[(src[1] + src[6] - 5*(src[2] + src[5]) + src[3]*C1 + src[4]*C2 + base_shift) >> SHIFT];
        dst[4] = cm[(src[2] + src[7] - 5*(src[3] + src[6]) + src[4]*C1 + src[5]*C2 + base_shift) >> SHIFT];
        dst[5] = cm[(src[3] + src[8] - 5*(src[4] + src[7]) + src[5]*C1 + src[6]*C2 + base_shift) >> SHIFT];
        dst[6] = cm[(src[4] + src[9] - 5*(src[5] + src[8]) + src[6]*C1 + src[7]*C2 + base_shift) >> SHIFT];
        dst[7] = cm[(src[5] + src[10]- 5*(src[6] + src[9]) + src[7]*C1 + src[8]*C2 + base_shift) >> SHIFT];

        uint8_t* dst_next = dst + dstStride;
        uint8_t* src_next = src + srcStride;

        // Second iteration
        dst_next[0] = cm[(src_next[-2] + src_next[3] - 5*(src_next[-1] + src_next[2]) + src_next[0]*C1 + src_next[1]*C2 + base_shift) >> SHIFT];
        dst_next[1] = cm[(src_next[-1] + src_next[4] - 5*(src_next[0] + src_next[3]) + src_next[1]*C1 + src_next[2]*C2 + base_shift) >> SHIFT];
        dst_next[2] = cm[(src_next[0] + src_next[5] - 5*(src_next[1] + src_next[4]) + src_next[2]*C1 + src_next[3]*C2 + base_shift) >> SHIFT];
        dst_next[3] = cm[(src_next[1] + src_next[6] - 5*(src_next[2] + src_next[5]) + src_next[3]*C1 + src_next[4]*C2 + base_shift) >> SHIFT];
        dst_next[4] = cm[(src_next[2] + src_next[7] - 5*(src_next[3] + src_next[6]) + src_next[4]*C1 + src_next[5]*C2 + base_shift) >> SHIFT];
        dst_next[5] = cm[(src_next[3] + src_next[8] - 5*(src_next[4] + src_next[7]) + src_next[5]*C1 + src_next[6]*C2 + base_shift) >> SHIFT];
        dst_next[6] = cm[(src_next[4] + src_next[9] - 5*(src_next[5] + src_next[8]) + src_next[6]*C1 + src_next[7]*C2 + base_shift) >> SHIFT];
        dst_next[7] = cm[(src_next[5] + src_next[10]- 5*(src_next[6] + src_next[9]) + src_next[7]*C1 + src_next[8]*C2 + base_shift) >> SHIFT];

        dst += 2 * dstStride;
        src += 2 * srcStride;
    } else {
        // Handle leftover row if h is odd
        dst[0] = cm[(src[-2] + src[3] - 5*(src[-1] + src[2]) + src[0]*C1 + src[1]*C2 + (1 << (SHIFT - 1))) >> SHIFT];
        dst[1] = cm[(src[-1] + src[4] - 5*(src[0] + src[3]) + src[1]*C1 + src[2]*C2 + (1 << (SHIFT - 1))) >> SHIFT];
        dst[2] = cm[(src[0] + src[5] - 5*(src[1] + src[4]) + src[2]*C1 + src[3]*C2 + (1 << (SHIFT - 1))) >> SHIFT];
        dst[3] = cm[(src[1] + src[6] - 5*(src[2] + src[5]) + src[3]*C1 + src[4]*C2 + (1 << (SHIFT - 1))) >> SHIFT];
        dst[4] = cm[(src[2] + src[7] - 5*(src[3] + src[6]) + src[4]*C1 + src[5]*C2 + (1 << (SHIFT - 1))) >> SHIFT];
        dst[5] = cm[(src[3] + src[8] - 5*(src[4] + src[7]) + src[5]*C1 + src[6]*C2 + (1 << (SHIFT - 1))) >> SHIFT];
        dst[6] = cm[(src[4] + src[9] - 5*(src[5] + src[8]) + src[6]*C1 + src[7]*C2 + (1 << (SHIFT - 1))) >> SHIFT];
        dst[7] = cm[(src[5] + src[10] - 5*(src[6] + src[9]) + src[7]*C1 + src[8]*C2 + (1 << (SHIFT - 1))) >> SHIFT];
        dst += dstStride;
        src += srcStride;
    }
}
}
