#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row / 4; i += 1) {
    for (BLASLONG j = 0; j < 4; j++) {
        dest0[4*j+0] = src0[2*j+0];
        dest0[4*j+1] = src0[2*j+1];
        dest0[4*j+2] = src1[2*j+0];
        dest0[4*j+3] = src1[2*j+1];
    }
    src0 += 8;
    src1 += 8;
    ii = (4 << 2);
    dest0 += ii;
}
}
