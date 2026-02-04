#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_local = b;
const BLASLONG lda8 = lda * 8;

for (ii = 0; ii < 8; ii++) {
    b_local[0] = a01[0 * lda];
    b_local[1] = a01[1 * lda];
    b_local[2] = a01[2 * lda];
    b_local[3] = a01[3 * lda];
    b_local[4] = a01[4 * lda];
    b_local[5] = a01[5 * lda];
    b_local[6] = a01[6 * lda];
    b_local[7] = a01[7 * lda];
    b_local[8] = a01[8 * lda];
    b_local[9] = a01[9 * lda];
    b_local[10] = a01[10 * lda];
    b_local[11] = a01[11 * lda];
    b_local[12] = a01[12 * lda];
    b_local[13] = a01[13 * lda];
    b_local[14] = a01[14 * lda];
    b_local[15] = a01[15 * lda];

    a01++;
    b_local += 16;
}

b += 128; 
}
