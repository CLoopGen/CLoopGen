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
    // Reduce arithmetic complexity by removing redundant loads and simplifying expressions
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];
    const int tmp5 = tmp[5 * 8];
    const int tmp6 = tmp[6 * 8];
    const int tmp7 = tmp[7 * 8];

    // Simplified filter: use only central terms with reduced coefficients
    const int sum0 = (5 * tmp0 + 5 * tmp1 - tmp2) + 256;
    const int sum1 = (5 * tmp1 + 5 * tmp2 - tmp3) + 256;
    const int sum2 = (5 * tmp2 + 5 * tmp3 - tmp4) + 256;
    const int sum3 = (5 * tmp3 + 5 * tmp4 - tmp5) + 256;

    dst[0 * dstStride] = cm[sum0 >> 9];  // Scale adjusted for lower shift
    dst[1 * dstStride] = cm[sum1 >> 9];
    dst[2 * dstStride] = cm[sum2 >> 9];
    dst[3 * dstStride] = cm[sum3 >> 9];

    // Skip unused outputs and reduce memory writes
    dst++;
    tmp++;
}
}
