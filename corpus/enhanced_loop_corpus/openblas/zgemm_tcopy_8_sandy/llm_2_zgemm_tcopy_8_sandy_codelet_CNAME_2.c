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
    for (BLASLONG j = 0; j < 16; j++) {
        dest0[j] = src0[j];
    }
    src0 = src0 + 16;
    ii = (row << 4);
    dest0 = dest0 + ii;
}
}
