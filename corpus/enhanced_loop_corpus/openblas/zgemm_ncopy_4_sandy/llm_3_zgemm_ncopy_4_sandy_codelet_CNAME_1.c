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
    BLASLONG idx = i * 8;
    BLASLONG j;
    for (j = 0; j < 8; j += 2) {
        dest0[(i * 16) + (j * 2) + 0] = src0[idx + j + 0];
        dest0[(i * 16) + (j * 2) + 1] = src0[idx + j + 1];
        dest0[(i * 16) + (j * 2) + 2] = src1[idx + j + 0];
        dest0[(i * 16) + (j * 2) + 3] = src1[idx + j + 1];
    }
}
}
