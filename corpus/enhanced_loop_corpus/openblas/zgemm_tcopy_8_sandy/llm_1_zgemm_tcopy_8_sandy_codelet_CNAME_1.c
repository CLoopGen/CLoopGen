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
    for (BLASLONG k = 0; k < 2; k++) {
        for (BLASLONG j = 0; j < 16; j++) {
            if (k == 0)
                dest0[j] = src0[j];
            else
                dest0[16 + j] = src1[j];
        }
    }
    src0 = src0 + 16;
    src1 = src1 + 16;
    ii = (row << 4);
    dest0 = dest0 + ii;
}
}
