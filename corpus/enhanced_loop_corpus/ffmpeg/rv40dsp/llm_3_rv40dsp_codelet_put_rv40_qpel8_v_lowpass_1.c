#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const uint8_t *s = src;
uint8_t *d = dst;
for (i = 0; i < w; i++) {
    const int offsets[] = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int* idx = offsets;
    const int srcB = s[*(idx++) * srcStride];
    const int srcA = s[*(idx++) * srcStride];
    const int src0 = s[*(idx++) * srcStride];
    const int src1 = s[*(idx++) * srcStride];
    const int src2 = s[*(idx++) * srcStride];
    const int src3 = s[*(idx++) * srcStride];
    const int src4 = s[*(idx++) * srcStride];
    const int src5 = s[*(idx++) * srcStride];
    const int src6 = s[*(idx++) * srcStride];
    const int src7 = s[*(idx++) * srcStride];
    const int src8 = s[*(idx++) * srcStride];
    const int src9 = s[*(idx++) * srcStride];
    const int src10 = s[*idx * srcStride];
    d[0] = cm[(srcB + src3 - 5 * (srcA + src2) + src0 * C1 + src1 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    d[dstStride] = cm[(srcA + src4 - 5 * (src0 + src3) + src1 * C1 + src2 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    d[2 * dstStride] = cm[(src0 + src5 - 5 * (src1 + src4) + src2 * C1 + src3 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    d[3 * dstStride] = cm[(src1 + src6 - 5 * (src2 + src5) + src3 * C1 + src4 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    d[4 * dstStride] = cm[(src2 + src7 - 5 * (src3 + src6) + src4 * C1 + src5 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    d[5 * dstStride] = cm[(src3 + src8 - 5 * (src4 + src7) + src5 * C1 + src6 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    d[6 * dstStride] = cm[(src4 + src9 - 5 * (src5 + src8) + src6 * C1 + src7 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    d[7 * dstStride] = cm[(src5 + src10 - 5 * (src6 + src9) + src7 * C1 + src8 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    d++;
    s++;
}
dst = d;
src = s;
}
