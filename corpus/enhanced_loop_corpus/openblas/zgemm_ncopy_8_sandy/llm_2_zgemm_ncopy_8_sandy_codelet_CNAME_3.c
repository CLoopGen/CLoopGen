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
    BLASLONG idx = i * 8;
    dest0[idx + 0] = src0[idx + 0];
    dest0[idx + 1] = src0[idx + 1];
    dest0[idx + 2] = src0[idx + 2];
    dest0[idx + 3] = src0[idx + 3];
    dest0[idx + 4] = src0[idx + 4];
    dest0[idx + 5] = src0[idx + 5];
    dest0[idx + 6] = src0[idx + 6];
    dest0[idx + 7] = src0[idx + 7];
}
}
