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
    BLASLONG base_src0 = i * 8;
    BLASLONG base_src1 = i * 8;
    BLASLONG base_dest = i * 16;
    dest0[base_dest + 0] = src0[base_src0 + 0];
    dest0[base_dest + 1] = src0[base_src0 + 1];
    dest0[base_dest + 2] = src1[base_src1 + 0];
    dest0[base_dest + 3] = src1[base_src1 + 1];
    dest0[base_dest + 4] = src0[base_src0 + 2];
    dest0[base_dest + 5] = src0[base_src0 + 3];
    dest0[base_dest + 6] = src1[base_src1 + 2];
    dest0[base_dest + 7] = src1[base_src1 + 3];
    dest0[base_dest + 8] = src0[base_src0 + 4];
    dest0[base_dest + 9] = src0[base_src0 + 5];
    dest0[base_dest + 10] = src1[base_src1 + 4];
    dest0[base_dest + 11] = src1[base_src1 + 5];
    dest0[base_dest + 12] = src0[base_src0 + 6];
    dest0[base_dest + 13] = src0[base_src0 + 7];
    dest0[base_dest + 14] = src1[base_src1 + 6];
    dest0[base_dest + 15] = src1[base_src1 + 7];
}
}
