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



void loop(){
for (i = 0; i < w; i++) {
    // Reduce arithmetic complexity by reusing common subexpressions and reducing coefficient variety
    const int t0 = tmp[0 * 8];
    const int t1 = tmp[1 * 8];
    const int t2 = tmp[2 * 8];
    const int t3 = tmp[3 * 8];

    // Simplified filtering kernel: only three terms instead of six, lower precision shift
    const int val0 = (t0 + t1 + 32 * src2[0 * srcStride] + 16) >> 5;
    const int val1 = (t1 + t2 + 32 * src2[1 * srcStride] + 16) >> 5;
    const int val2 = (t2 + t3 + 32 * src2[2 * srcStride] + 16) >> 5;

    dst[0 * dstStride] = cm[val0];
    dst[1 * dstStride] = cm[val1];
    dst[2 * dstStride] = cm[val2];

    // Only update pointers partially — simulate reduced working set
    dst++;
    tmp++;
    src2++;
}
}
