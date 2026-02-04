#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Index Map (Simulating Irregular Memory Access)
    // Use a fixed index map to simulate indirect or reordered access pattern for tmp array
    static const int index_map[13] = {
        -2*8, -1*8, 0*8, 1*8, 2*8, 3*8, 4*8, 5*8, 6*8, 7*8, 8*8, 9*8, 10*8
    };
    for (i = 0; i < w; i++) {
        const int tmpB  = tmp[index_map[0]];
        const int tmpA  = tmp[index_map[1]];
        const int tmp0  = tmp[index_map[2]];
        const int tmp1  = tmp[index_map[3]];
        const int tmp2  = tmp[index_map[4]];
        const int tmp3  = tmp[index_map[5]];
        const int tmp4  = tmp[index_map[6]];
        const int tmp5  = tmp[index_map[7]];
        const int tmp6  = tmp[index_map[8]];
        const int tmp7  = tmp[index_map[9]];
        const int tmp8  = tmp[index_map[10]];
        const int tmp9  = tmp[index_map[11]];
        const int tmp10 = tmp[index_map[12]];

        dst[0 * dstStride] = cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3) + 64) >> 7];
        dst[1 * dstStride] = cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4) + 64) >> 7];
        dst[2 * dstStride] = cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5) + 64) >> 7];
        dst[3 * dstStride] = cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6) + 64) >> 7];
        dst[4 * dstStride] = cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7) + 64) >> 7];
        dst[5 * dstStride] = cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8) + 64) >> 7];
        dst[6 * dstStride] = cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9) + 64) >> 7];
        dst[7 * dstStride] = cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10) + 64) >> 7];

        dst++;
        tmp++;
    }
}
