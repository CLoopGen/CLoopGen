#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access via Pointer Arithmetic with Unrolled Step
    // Use pointer arithmetic with precomputed offsets to simulate a more regular strided pattern.
    // This variant unrolls by 2 iterations and uses direct pointer arithmetic to enhance stride predictability.

    uint8_t *src0, *src1;
    uint8_t *dst0, *dst1;

    for (i = 0; i < h; i += 2) {
        src0 = src;
        dst0 = dst;
        src1 = src + srcStride;
        dst1 = dst + dstStride;

        // First iteration
        dst0[0] = cm[(((src0[0] + src0[1]) * 20 - (src0[0] + src0[2]) * 6 + (src0[1] + src0[3]) * 3 - (src0[2] + src0[4])) + 15) >> 5];
        dst0[1] = cm[(((src0[1] + src0[2]) * 20 - (src0[0] + src0[3]) * 6 + (src0[0] + src0[4]) * 3 - (src0[1] + src0[5])) + 15) >> 5];
        dst0[2] = cm[(((src0[2] + src0[3]) * 20 - (src0[1] + src0[4]) * 6 + (src0[0] + src0[5]) * 3 - (src0[0] + src0[6])) + 15) >> 5];
        dst0[3] = cm[(((src0[3] + src0[4]) * 20 - (src0[2] + src0[5]) * 6 + (src0[1] + src0[6]) * 3 - (src0[0] + src0[7])) + 15) >> 5];
        dst0[4] = cm[(((src0[4] + src0[5]) * 20 - (src0[3] + src0[6]) * 6 + (src0[2] + src0[7]) * 3 - (src0[1] + src0[8])) + 15) >> 5];
        dst0[5] = cm[(((src0[5] + src0[6]) * 20 - (src0[4] + src0[7]) * 6 + (src0[3] + src0[8]) * 3 - (src0[2] + src0[9])) + 15) >> 5];
        dst0[6] = cm[(((src0[6] + src0[7]) * 20 - (src0[5] + src0[8]) * 6 + (src0[4] + src0[9]) * 3 - (src0[3] + src0[10])) + 15) >> 5];
        dst0[7] = cm[(((src0[7] + src0[8]) * 20 - (src0[6] + src0[9]) * 6 + (src0[5] + src0[10]) * 3 - (src0[4] + src0[11])) + 15) >> 5];
        dst0[8] = cm[(((src0[8] + src0[9]) * 20 - (src0[7] + src0[10]) * 6 + (src0[6] + src0[11]) * 3 - (src0[5] + src0[12])) + 15) >> 5];
        dst0[9] = cm[(((src0[9] + src0[10]) * 20 - (src0[8] + src0[11]) * 6 + (src0[7] + src0[12]) * 3 - (src0[6] + src0[13])) + 15) >> 5];
        dst0[10] = cm[(((src0[10] + src0[11]) * 20 - (src0[9] + src0[12]) * 6 + (src0[8] + src0[13]) * 3 - (src0[7] + src0[14])) + 15) >> 5];
        dst0[11] = cm[(((src0[11] + src0[12]) * 20 - (src0[10] + src0[13]) * 6 + (src0[9] + src0[14]) * 3 - (src0[8] + src0[15])) + 15) >> 5];
        dst0[12] = cm[(((src0[12] + src0[13]) * 20 - (src0[11] + src0[14]) * 6 + (src0[10] + src0[15]) * 3 - (src0[9] + src0[16])) + 15) >> 5];
        dst0[13] = cm[(((src0[13] + src0[14]) * 20 - (src0[12] + src0[15]) * 6 + (src0[11] + src0[16]) * 3 - (src0[10] + src0[16])) + 15) >> 5];
        dst0[14] = cm[(((src0[14] + src0[15]) * 20 - (src0[13] + src0[16]) * 6 + (src0[12] + src0[16]) * 3 - (src0[11] + src0[15])) + 15) >> 5];
        dst0[15] = cm[(((src0[15] + src0[16]) * 20 - (src0[14] + src0[16]) * 6 + (src0[13] + src0[15]) * 3 - (src0[12] + src0[14])) + 15) >> 5];

        // Second iteration (if valid)
        if (i + 1 < h) {
            dst1[0] = cm[(((src1[0] + src1[1]) * 20 - (src1[0] + src1[2]) * 6 + (src1[1] + src1[3]) * 3 - (src1[2] + src1[4])) + 15) >> 5];
            dst1[1] = cm[(((src1[1] + src1[2]) * 20 - (src1[0] + src1[3]) * 6 + (src1[0] + src1[4]) * 3 - (src1[1] + src1[5])) + 15) >> 5];
            dst1[2] = cm[(((src1[2] + src1[3]) * 20 - (src1[1] + src1[4]) * 6 + (src1[0] + src1[5]) * 3 - (src1[0] + src1[6])) + 15) >> 5];
            dst1[3] = cm[(((src1[3] + src1[4]) * 20 - (src1[2] + src1[5]) * 6 + (src1[1] + src1[6]) * 3 - (src1[0] + src1[7])) + 15) >> 5];
            dst1[4] = cm[(((src1[4] + src1[5]) * 20 - (src1[3] + src1[6]) * 6 + (src1[2] + src1[7]) * 3 - (src1[1] + src1[8])) + 15) >> 5];
            dst1[5] = cm[(((src1[5] + src1[6]) * 20 - (src1[4] + src1[7]) * 6 + (src1[3] + src1[8]) * 3 - (src1[2] + src1[9])) + 15) >> 5];
            dst1[6] = cm[(((src1[6] + src1[7]) * 20 - (src1[5] + src1[8]) * 6 + (src1[4] + src1[9]) * 3 - (src1[3] + src1[10])) + 15) >> 5];
            dst1[7] = cm[(((src1[7] + src1[8]) * 20 - (src1[6] + src1[9]) * 6 + (src1[5] + src1[10]) * 3 - (src1[4] + src1[11])) + 15) >> 5];
            dst1[8] = cm[(((src1[8] + src1[9]) * 20 - (src1[7] + src1[10]) * 6 + (src1[6] + src1[11]) * 3 - (src1[5] + src1[12])) + 15) >> 5];
            dst1[9] = cm[(((src1[9] + src1[10]) * 20 - (src1[8] + src1[11]) * 6 + (src1[7] + src1[12]) * 3 - (src1[6] + src1[13])) + 15) >> 5];
            dst1[10] = cm[(((src1[10] + src1[11]) * 20 - (src1[9] + src1[12]) * 6 + (src1[8] + src1[13]) * 3 - (src1[7] + src1[14])) + 15) >> 5];
            dst1[11] = cm[(((src1[11] + src1[12]) * 20 - (src1[10] + src1[13]) * 6 + (src1[9] + src1[14]) * 3 - (src1[8] + src1[15])) + 15) >> 5];
            dst1[12] = cm[(((src1[12] + src1[13]) * 20 - (src1[11] + src1[14]) * 6 + (src1[10] + src1[15]) * 3 - (src1[9] + src1[16])) + 15) >> 5];
            dst1[13] = cm[(((src1[13] + src1[14]) * 20 - (src1[12] + src1[15]) * 6 + (src1[11] + src1[16]) * 3 - (src1[10] + src1[16])) + 15) >> 5];
            dst1[14] = cm[(((src1[14] + src1[15]) * 20 - (src1[13] + src1[16]) * 6 + (src1[12] + src1[16]) * 3 - (src1[11] + src1[15])) + 15) >> 5];
            dst1[15] = cm[(((src1[15] + src1[16]) * 20 - (src1[14] + src1[16]) * 6 + (src1[13] + src1[15]) * 3 - (src1[12] + src1[14])) + 15) >> 5];
        }

        dst += 2 * dstStride;
        src += 2 * srcStride;
    }
}
