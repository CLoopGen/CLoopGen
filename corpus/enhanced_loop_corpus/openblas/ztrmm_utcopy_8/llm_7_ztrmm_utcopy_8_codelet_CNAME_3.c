#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float val1, val2, val3, val4;
for (ii = 0; ii < i; ii++) {
    val1 = *(a01 + 0);
    val2 = *(a02 + 0);
    val3 = *(a03 + 0);
    val4 = *(a04 + 0);
    b[0] = val1;
    b[1] = val2;
    b[2] = val3;
    b[3] = val4;
    b[4] = val1 + val2;
    b[5] = val2 + val3;
    b[6] = val3 + val4;
    b[7] = val4 + val1;
    a01 += lda;
    a02 += lda;
    a03 += lda;
    a04 += lda;
    b += 8;
}
}
