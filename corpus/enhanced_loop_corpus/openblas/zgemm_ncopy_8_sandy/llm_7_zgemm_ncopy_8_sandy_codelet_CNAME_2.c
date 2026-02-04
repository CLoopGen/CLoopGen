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
BLASLONG temp0[8], temp1[8];
for (i = 0; i < row / 4; i += 1) {
    BLASLONG src0_idx = i * 8;
    BLASLONG src1_idx = i * 8;
    BLASLONG dest_idx = i * 16;

    temp0[0] = src0[src0_idx + 0]; temp1[0] = src1[src1_idx + 0];
    temp0[1] = src0[src0_idx + 1]; temp1[1] = src1[src1_idx + 1];
    temp0[2] = src0[src0_idx + 2]; temp1[2] = src1[src1_idx + 2];
    temp0[3] = src0[src0_idx + 3]; temp1[3] = src1[src1_idx + 3];
    temp0[4] = src0[src0_idx + 4]; temp1[4] = src1[src1_idx + 4];
    temp0[5] = src0[src0_idx + 5]; temp1[5] = src1[src1_idx + 5];
    temp0[6] = src0[src0_idx + 6]; temp1[6] = src1[src1_idx + 6];
    temp0[7] = src0[src0_idx + 7]; temp1[7] = src1[src1_idx + 7];

    dest0[dest_idx + 0] = temp0[0];
    dest0[dest_idx + 1] = temp0[1];
    dest0[dest_idx + 2] = temp1[0];
    dest0[dest_idx + 3] = temp1[1];
    dest0[dest_idx + 4] = temp0[2];
    dest0[dest_idx + 5] = temp0[3];
    dest0[dest_idx + 6] = temp1[2];
    dest0[dest_idx + 7] = temp1[3];
    dest0[dest_idx + 8] = temp0[4];
    dest0[dest_idx + 9] = temp0[5];
    dest0[dest_idx + 10] = temp1[4];
    dest0[dest_idx + 11] = temp1[5];
    dest0[dest_idx + 12] = temp0[6];
    dest0[dest_idx + 13] = temp0[7];
    dest0[dest_idx + 14] = temp1[6];
    dest0[dest_idx + 15] = temp1[7];
}
}
