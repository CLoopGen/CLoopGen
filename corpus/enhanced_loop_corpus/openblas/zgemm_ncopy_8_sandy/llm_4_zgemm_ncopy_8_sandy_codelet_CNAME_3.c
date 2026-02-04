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
    if (i % 2 == 0) {
        dest0[0] = src0[0];
        dest0[1] = src0[1];
        dest0[2] = src0[2];
        dest0[3] = src0[3];
    } else {
        dest0[4] = src0[4];
        dest0[5] = src0[5];
        dest0[6] = src0[6];
        dest0[7] = src0[7];
    }
    src0 = src0 + 8;
    ii = (4 << 1);
    dest0 = dest0 + ii;
}
}
