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
for (i = 0; i < w; i++) {
    const int16_t *tmp_offset = &tmp[0];
    const int tmpB = tmp_offset[-2 * 8];
    const int tmpA = tmp_offset[-1 * 8];
    const int tmp0 = tmp_offset[0 * 8];
    const int tmp1 = tmp_offset[1 * 8];
    const int tmp2 = tmp_offset[2 * 8];
    const int tmp3 = tmp_offset[3 * 8];
    const int tmp4 = tmp_offset[4 * 8];
    const int tmp5 = tmp_offset[5 * 8];
    const int tmp6 = tmp_offset[6 * 8];
    const int tmp7 = tmp_offset[7 * 8];
    const int tmp8 = tmp_offset[8 * 8];
    const int tmp9 = tmp_offset[9 * 8];
    const int tmp10 = tmp_offset[10 * 8];

    uint8_t *dst_ptr = dst;
    ptrdiff_t stride = dstStride;

    dst_ptr[0 * stride] = cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3) + 512) >> 10];
    dst_ptr[1 * stride] = cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4) + 512) >> 10];
    dst_ptr[2 * stride] = cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5) + 512) >> 10];
    dst_ptr[3 * stride] = cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6) + 512) >> 10];
    dst_ptr[4 * stride] = cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7) + 512) >> 10];
    dst_ptr[5 * stride] = cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8) + 512) >> 10];
    dst_ptr[6 * stride] = cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9) + 512) >> 10];
    dst_ptr[7 * stride] = cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10) + 512) >> 10];

    dst += 1;
    tmp += 1;
}
}
