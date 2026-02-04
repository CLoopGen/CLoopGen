#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 16; ii++) {
    if (ii % 2 == 0) {
        b[0] = a01[0];
        b[1] = a01[1];
        b[2] = a01[2];
        b[3] = a01[3];
        b[4] = a01[4];
        b[5] = a01[5];
        b[6] = a01[6];
        b[7] = a01[7];
    } else {
        b[8] = a01[8];
        b[9] = a01[9];
        b[10] = a01[10];
        b[11] = a01[11];
        b[12] = a01[12];
        b[13] = a01[13];
        b[14] = a01[14];
        b[15] = a01[15];
    }
    a01 += lda;
    b += 16;
}
}
