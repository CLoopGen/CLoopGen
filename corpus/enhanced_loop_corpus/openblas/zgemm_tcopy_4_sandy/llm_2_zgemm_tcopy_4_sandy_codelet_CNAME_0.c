#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern float *src;
extern BLASLONG srcdim;
extern float *dest;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *src2;
extern float *src3;
extern float *dest0;
extern float *dest1;
extern float *dest2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < row / 4; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src = src3 + 2 * srcdim;
    dest0 = dest;
    ii = (4 << 3);
    dest = dest + ii;
    for (i = 0; i < col / 4; i += 1) {
        // Change memory access to consecutive stores using array of pointers
        float *d0 = &dest0[0];
        const float *s0 = &src0[0], *s1 = &src1[0], *s2 = &src2[0], *s3 = &src3[0];
        
        for (int k = 0; k < 8; k++) {
            d0[k]      = s0[k];  // Copy 8 elements from src0
            d0[k + 8]  = s1[k];  // Copy 8 elements from src1
            d0[k + 16] = s2[k];  // Copy 8 elements from src2
            d0[k + 24] = s3[k];  // Copy 8 elements from src3
        }
        
        src0 += 8;
        src1 += 8;
        src2 += 8;
        src3 += 8;
        ii = (row << 3);
        dest0 = dest0 + ii;
    }
    if (col & 2) {
        float *d2 = dest2;
        const float *s0 = src0, *s1 = src1, *s2 = src2, *s3 = src3;
        for (int k = 0; k < 4; k++) {
            d2[k]       = s0[k];
            d2[k + 4]   = s1[k];
            d2[k + 8]   = s2[k];
            d2[k + 12]  = s3[k];
        }
        src0 += 4;
        src1 += 4;
        src2 += 4;
        src3 += 4;
        dest2 += 16;
    }
    if (col & 1) {
        float *d1 = dest1;
        d1[0] = src0[0]; d1[1] = src0[1];
        d1[2] = src1[0]; d1[3] = src1[1];
        d1[4] = src2[0]; d1[5] = src2[1];
        d1[6] = src3[0]; d1[7] = src3[1];
        src0 += 2;
        src1 += 2;
        src2 += 2;
        src3 += 2;
        dest1 += 8;
    }
}
}
