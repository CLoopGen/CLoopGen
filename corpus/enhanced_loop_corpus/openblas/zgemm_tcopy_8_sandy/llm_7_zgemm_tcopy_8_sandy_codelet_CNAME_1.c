#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG temp_dest[32];
for (i = 0; i < col / 8; i += 1) {
    temp_dest[0] = src0[0];
    temp_dest[1] = src0[1];
    temp_dest[2] = src0[2];
    temp_dest[3] = src0[3];
    temp_dest[4] = src0[4];
    temp_dest[5] = src0[5];
    temp_dest[6] = src0[6];
    temp_dest[7] = src0[7];
    temp_dest[8] = src0[8];
    temp_dest[9] = src0[9];
    temp_dest[10] = src0[10];
    temp_dest[11] = src0[11];
    temp_dest[12] = src0[12];
    temp_dest[13] = src0[13];
    temp_dest[14] = src0[14];
    temp_dest[15] = src0[15];
    temp_dest[16] = src1[0];
    temp_dest[17] = src1[1];
    temp_dest[18] = src1[2];
    temp_dest[19] = src1[3];
    temp_dest[20] = src1[4];
    temp_dest[21] = src1[5];
    temp_dest[22] = src1[6];
    temp_dest[23] = src1[7];
    temp_dest[24] = src1[8];
    temp_dest[25] = src1[9];
    temp_dest[26] = src1[10];
    temp_dest[27] = src1[11];
    temp_dest[28] = src1[12];
    temp_dest[29] = src1[13];
    temp_dest[30] = src1[14];
    temp_dest[31] = src1[15];
    for (ii = 0; ii < 32; ii++) {
        dest0[ii] = temp_dest[ii];
    }
    src0 += 16;
    src1 += 16;
    ii = (row << 4);
    dest0 += ii;
}
}
