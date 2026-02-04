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
    b[0] = *(a01 + 0);
    b[1] = *(a01 + 1);
    b[2] = *(a01 + 2);
    b[3] = *(a01 + 3);
    a01 += lda;
    a02 += lda;
    a03 += lda;
    a04 += lda;
    b += 4;
}

}
