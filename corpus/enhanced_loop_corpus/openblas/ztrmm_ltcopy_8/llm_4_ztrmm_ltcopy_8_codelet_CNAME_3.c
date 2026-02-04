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
for (ii = 0; ii < i; ii++) {
    if (ii % 2 == 0) {
        b[0] = *(a01 + 0);
        b[1] = *(a01 + 1);
        b[2] = *(a01 + 2);
        b[3] = *(a01 + 3);
        b[4] = *(a01 + 4);
        b[5] = *(a01 + 5);
        b[6] = *(a01 + 6);
        b[7] = *(a01 + 7);
    } else {
        b[0] = *(a02 + 0);
        b[1] = *(a02 + 1);
        b[2] = *(a02 + 2);
        b[3] = *(a02 + 3);
        b[4] = *(a02 + 4);
        b[5] = *(a02 + 5);
        b[6] = *(a02 + 6);
        b[7] = *(a02 + 7);
    }
    a01 += lda;
    a02 += lda;
    a03 += lda;
    a04 += lda;
    b += 8;
}
}
