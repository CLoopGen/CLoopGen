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
    for (BLASLONG j = 0; j < 8; j += 1) {
        dest0[j] = src0[j];
        dest0[j + 8] = src1[j];
    }
    src0 = src0 + 8;
    src1 = src1 + 8;
    ii = (row << 3);
    dest0 = dest0 + ii;
}
}
