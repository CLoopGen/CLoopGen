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



void loop(){
    // Variant 2: Indirect Access via Index Array (Simulating Irregular Access Pattern)
    // Use an index array to simulate indirect memory access, changing the access pattern to indirect.
    // This can help in scenarios where data-dependent or scatter-like access is needed.
    static const int indices[] = {-16, -8, 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80}; // Scaled offsets: n * 8 mapped to index
    for (i = 0; i < w; i++) {
        const int tmpB = tmp[indices[0]];
        const int tmpA = tmp[indices[1]];
        const int tmp0 = tmp[indices[2]];
        const int tmp1 = tmp[indices[3]];
        const int tmp2 = tmp[indices[4]];
        const int tmp3 = tmp[indices[5]];
        const int tmp4 = tmp[indices[6]];
        const int tmp5 = tmp[indices[7]];
        const int tmp6 = tmp[indices[8]];
        const int tmp7 = tmp[indices[9]];
        const int tmp8 = tmp[indices[10]];
        const int tmp9 = tmp[indices[11]];
        const int tmp10 = tmp[indices[12]];

        dst[0 * dstStride] = cm[((0 * tmpB + -7 * tmpA + 42 * tmp0 + 96 * tmp1 + -2 * tmp2 + -1 * tmp3) + 512) >> 10];
        dst[1 * dstStride] = cm[((0 * tmpA + -7 * tmp0 + 42 * tmp1 + 96 * tmp2 + -2 * tmp3 + -1 * tmp4) + 512) >> 10];
        dst[2 * dstStride] = cm[((0 * tmp0 + -7 * tmp1 + 42 * tmp2 + 96 * tmp3 + -2 * tmp4 + -1 * tmp5) + 512) >> 10];
        dst[3 * dstStride] = cm[((0 * tmp1 + -7 * tmp2 + 42 * tmp3 + 96 * tmp4 + -2 * tmp5 + -1 * tmp6) + 512) >> 10];
        dst[4 * dstStride] = cm[((0 * tmp2 + -7 * tmp3 + 42 * tmp4 + 96 * tmp5 + -2 * tmp6 + -1 * tmp7) + 512) >> 10];
        dst[5 * dstStride] = cm[((0 * tmp3 + -7 * tmp4 + 42 * tmp5 + 96 * tmp6 + -2 * tmp7 + -1 * tmp8) + 512) >> 10];
        dst[6 * dstStride] = cm[((0 * tmp4 + -7 * tmp5 + 42 * tmp6 + 96 * tmp7 + -2 * tmp8 + -1 * tmp9) + 512) >> 10];
        dst[7 * dstStride] = cm[((0 * tmp5 + -7 * tmp6 + 42 * tmp7 + 96 * tmp8 + -2 * tmp9 + -1 * tmp10) + 512) >> 10];

        dst++;
        tmp++;
    }
}
