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
    BLASLONG idx = i * 4;
    BLASLONG offset0 = idx * 2;
    BLASLONG offset1 = idx * 2;
    for (BLASLONG j = 0; j < 4; ++j) {
        dest0[offset0 + 0] = src0[j * 2 + 0];
        dest0[offset0 + 1] = src0[j * 2 + 1];
        dest0[offset0 + 2] = src1[j * 2 + 0];
        dest0[offset0 + 3] = src1[j * 2 + 1];
        offset0 += 4;
    }
    src0 += 8;
    src1 += 8;
    dest0 += 16;
}
}
