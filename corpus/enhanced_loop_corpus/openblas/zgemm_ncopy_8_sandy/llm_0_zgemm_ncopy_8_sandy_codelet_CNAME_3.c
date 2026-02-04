#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row / 4; i += 1) {
    for (BLASLONG j = 0; j < 2; j++) {
        dest0[0 + j*4] = src0[0 + j*4];
        dest0[1 + j*4] = src0[1 + j*4];
        dest0[2 + j*4] = src0[2 + j*4];
        dest0[3 + j*4] = src0[3 + j*4];
    }
    src0 = src0 + 8;
    ii = (4 << 1);
    dest0 = dest0 + ii;
}
}
