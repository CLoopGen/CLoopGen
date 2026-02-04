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
BLASLONG stride = row << 3;
for (i = 0; i < col / 4; i += 1) {
    BLASLONG base_dest = i * stride;
    BLASLONG base_src0 = i * 8;
    BLASLONG base_src1 = i * 8;
    // Interleaved write pattern: write one from src0, then one from src1, alternating
    for (BLASLONG j = 0; j < 8; j++) {
        dest0[base_dest + j * 2]     = src0[base_src0 + j];
        dest0[base_dest + j * 2 + 1] = src1[base_src1 + j];
    }
    // Remaining elements written consecutively to avoid overlap
    for (BLASLONG j = 8; j < 16; j++) {
        if (j < 16) {
            dest0[base_dest + 16 + (j - 8)] = src0[base_src0 + j];
            dest0[base_dest + 24 + (j - 8)] = src1[base_src1 + j];
        }
    }
}
}
