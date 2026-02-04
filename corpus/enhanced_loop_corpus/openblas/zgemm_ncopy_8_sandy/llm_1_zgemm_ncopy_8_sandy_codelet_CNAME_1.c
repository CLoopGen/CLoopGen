#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *src2;
extern float *src3;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row / 4; i += 1) {
    for (BLASLONG k = 0; k < 8; k++) {
        dest0[k]             = src0[k];
        dest0[k + 8]         = src1[k];
        dest0[k + 16]        = src2[k];
        dest0[k + 24]        = src3[k];
    }
    src0 = src0 + 8;
    src1 = src1 + 8;
    src2 = src2 + 8;
    src3 = src3 + 8;
    ii = (4 << 3);
    dest0 = dest0 + ii;
}
}
