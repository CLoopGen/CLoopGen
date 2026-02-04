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
for (i = 0; i < col / 2; i += 1) {
    dest0[0] = src0[0];
    dest0[1] = src0[1];
    dest0[2] = src1[0];
    dest0[3] = src1[1];
    src0 = src0 + 2;
    src1 = src1 + 2;
    ii = (row << 2);
    dest0 = dest0 + ii;
}
}
