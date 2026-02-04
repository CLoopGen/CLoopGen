#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < col / 8; i += 1) {
    BLASLONG offset = 0;
    for (BLASLONG k = 0; k < row; k++) {
        dest0[offset + 0] = src0[0];
        dest0[offset + 1] = src0[1];
        dest0[offset + 2] = src0[2];
        dest0[offset + 3] = src0[3];
        dest0[offset + 4] = src0[4];
        dest0[offset + 5] = src0[5];
        dest0[offset + 6] = src0[6];
        dest0[offset + 7] = src0[7];
        dest0[offset + 8] = src0[8];
        dest0[offset + 9] = src0[9];
        dest0[offset + 10] = src0[10];
        dest0[offset + 11] = src0[11];
        dest0[offset + 12] = src0[12];
        dest0[offset + 13] = src0[13];
        dest0[offset + 14] = src0[14];
        dest0[offset + 15] = src0[15];
        offset += row << 4;
    }
    src0 += 16;
}
}
