#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < w; i++) {
        for (int k = 0; k < 8; k++) {
            const int src_offsets[] = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            const int coeffs[8][6] = {
                {  0, -7, 42, 96, -2, -1 }, // srcB to src3
                {  0, -7, 42, 96, -2, -1 }, // srcA to src4
                {  0, -7, 42, 96, -2, -1 }, // src0 to src5
                {  0, -7, 42, 96, -2, -1 }, // src1 to src6
                {  0, -7, 42, 96, -2, -1 }, // src2 to src7
                {  0, -7, 42, 96, -2, -1 }, // src3 to src8
                {  0, -7, 42, 96, -2, -1 }, // src4 to src9
                {  0, -7, 42, 96, -2, -1 }  // src5 to src10
            };

            int sum = 0;
            for (int c = 0; c < 6; c++) {
                int idx = k + c;
                uint8_t* s = src + src_offsets[idx] * srcStride;
                sum += coeffs[k][c] * (*s);
            }

            dst[k * dstStride] = ((dst[k * dstStride]) + cm[(sum + 64) >> 7] + 1) >> 1;
        }
        dst++;
        src++;
    }
}
