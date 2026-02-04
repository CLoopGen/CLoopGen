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
BLASLONG stride = row << 4;
for (i = 0; i < col / 8; i += 1) {
    BLASLONG base_idx = i << 4; 
    for (BLASLONG j = 0; j < 16; j++) {
        BLASLONG idx = j * stride + base_idx;
        dest0[idx] = src0[j];
        dest0[idx + 16] = src1[j];
    }
    src0 += 16;
    src1 += 16;
}
}
