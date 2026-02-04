#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Pointer Arithmetic Unrolling
    // Restructure memory access to use fixed offset arrays (simulating gather),
    // improving predictability and enabling potential vectorization.
    const int offsets[13] = {
        -src_stride - 2, -src_stride, -src_stride + 2,
        0 - 2, 0, 0 + 2,
        src_stride - 2, src_stride, src_stride + 2,
        2*src_stride - 2, 2*src_stride, 2*src_stride + 2,
        2*src_stride + 4
    };
    uint16_t vals[13];

    for (i = 2; i < width - 2; i += 2) {
        // Pre-load all required source values using offset table
        for (int j = 0; j < 13; j++) {
            vals[j] = ((const union unaligned_16*)&src[offsets[j]])->l;
        }

        // Compute and store outputs using local variables
        dst[0*dst_stride + 0*3 + 2] = (vals[1] + vals[3] + vals[7] + vals[9]) >> 10;
        dst[0*dst_stride + 0*3 + 1] = (vals[0] + vals[2] + vals[6] + vals[8]) >> 10;
        dst[0*dst_stride + 0*3 + 0] = vals[4] >> 8;
        dst[0*dst_stride + 1*3 + 2] = (vals[3] + vals[9]) >> 9;
        dst[0*dst_stride + 1*3 + 1] = vals[5] >> 8;
        dst[0*dst_stride + 1*3 + 0] = (vals[4] + vals[5]) >> 9;
        dst[1*dst_stride + 0*3 + 2] = (vals[7] + vals[9]) >> 9;
        dst[1*dst_stride + 0*3 + 1] = vals[8] >> 8;
        dst[1*dst_stride + 0*3 + 0] = (vals[4] + vals[10]) >> 9;
        dst[1*dst_stride + 1*3 + 2] = vals[9] >> 8;
        dst[1*dst_stride + 1*3 + 1] = (vals[5] + vals[8] + vals[9] + vals[11]) >> 10;
        dst[1*dst_stride + 1*3 + 0] = (vals[4] + vals[5] + vals[10] + vals[11]) >> 10;

        src += 4;
        dst += 6;
    }
}
