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
// Eliminate loop-carried dependency on 'tmp' by pre-loading a window of data
int window[13]; // Hold tmp[-2] to tmp[10], scaled by 8
for (i = 0; i < w; i++) {
    // Shift the window: simulate sliding window without re-reading all
    if (i == 0) {
        for (int j = -2; j <= 10; j++) {
            window[j + 2] = tmp[j * 8];
        }
    } else {
        // Slide window: remove oldest, shift left, load new
        for (int j = 0; j < 12; j++) {
            window[j] = window[j + 1];
        }
        window[12] = tmp[10 * 8]; // Load only the newest element
    }

    const int tmpB = window[0]; // tmp[-2*8]
    const int tmpA = window[1]; // tmp[-1*8]
    const int tmp0 = window[2]; // tmp[ 0*8]
    const int tmp1 = window[3]; // tmp[ 1*8]
    const int tmp2 = window[4]; // tmp[ 2*8]
    const int tmp3 = window[5]; // tmp[ 3*8]
    const int tmp4 = window[6]; // tmp[ 4*8]
    const int tmp5 = window[7]; // tmp[ 5*8]
    const int tmp6 = window[8]; // tmp[ 6*8]
    const int tmp7 = window[9]; // tmp[ 7*8]
    const int tmp8 = window[10]; // tmp[ 8*8]
    const int tmp9 = window[11]; // tmp[ 9*8]
    const int tmp10 = window[12]; // tmp[10*8]

    // Compute all outputs using the windowed data
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((-1 * tmpB + -2 * tmpA + 96 * tmp0 + 42 * tmp1 + -7 * tmp2 + 0 * tmp3) + 512) >> 10] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((-1 * tmpA + -2 * tmp0 + 96 * tmp1 + 42 * tmp2 + -7 * tmp3 + 0 * tmp4) + 512) >> 10] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((-1 * tmp0 + -2 * tmp1 + 96 * tmp2 + 42 * tmp3 + -7 * tmp4 + 0 * tmp5) + 512) >> 10] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((-1 * tmp1 + -2 * tmp2 + 96 * tmp3 + 42 * tmp4 + -7 * tmp5 + 0 * tmp6) + 512) >> 10] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((-1 * tmp2 + -2 * tmp3 + 96 * tmp4 + 42 * tmp5 + -7 * tmp6 + 0 * tmp7) + 512) >> 10] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((-1 * tmp3 + -2 * tmp4 + 96 * tmp5 + 42 * tmp6 + -7 * tmp7 + 0 * tmp8) + 512) >> 10] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((-1 * tmp4 + -2 * tmp5 + 96 * tmp6 + 42 * tmp7 + -7 * tmp8 + 0 * tmp9) + 512) >> 10] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((-1 * tmp5 + -2 * tmp6 + 96 * tmp7 + 42 * tmp8 + -7 * tmp9 + 0 * tmp10) + 512) >> 10] + 1) >> 1;

    dst++;
    tmp++;
}
}
