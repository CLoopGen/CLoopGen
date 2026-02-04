#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_local = b;
for (ii = 0; ii < 8; ii++) {
    b_local[0] = *(a01 + 0);
    b_local[1] = *(a01 + 1);
    b_local[2] = *(a01 + 2);
    b_local[3] = *(a01 + 3);
    b_local[4] = *(a01 + 4);
    b_local[5] = *(a01 + 5);
    b_local[6] = *(a01 + 6);
    b_local[7] = *(a01 + 7);
    a01 += lda;
    b_local += 8;
}
b = b_local;
}
