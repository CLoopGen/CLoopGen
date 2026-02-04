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
for (i = 0; i < col / 8; i += 1) {
    BLASLONG offset_dest = i * (row << 4);
    for (BLASLONG j = 0; j < 16; j++) {
        dest0[offset_dest + j] = src0[j];
        dest0[offset_dest + j + 16] = src1[j];
    }
    src0 += 16;
    src1 += 16;
}
}
