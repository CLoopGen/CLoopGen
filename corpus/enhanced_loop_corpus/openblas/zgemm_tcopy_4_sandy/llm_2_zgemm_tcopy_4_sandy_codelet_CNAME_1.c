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
for (i = 0; i < col / 4; i += 1) {
    BLASLONG offset_src0 = i * 8;
    BLASLONG offset_src1 = i * 8;
    BLASLONG offset_dest = i * (row << 3);
    for (BLASLONG j = 0; j < 8; j++) {
        dest0[offset_dest + j] = src0[offset_src0 + j];
    }
    for (BLASLONG j = 0; j < 8; j++) {
        dest0[offset_dest + 8 + j] = src1[offset_src1 + j];
    }
}
}
