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
for (i = 0; i < col / 4; i += 1) {
    for (BLASLONG j = 0; j < 4; j++) {
        dest0[j*4+0] = src0[j*4+0];
        dest0[j*4+1] = src0[j*4+1];
        dest0[j*4+2] = src0[j*4+2];
        dest0[j*4+3] = src0[j*4+3];
    }
    src0 = src0 + 16;
    ii = (row << 4);
    dest0 = dest0 + ii;
}
}
