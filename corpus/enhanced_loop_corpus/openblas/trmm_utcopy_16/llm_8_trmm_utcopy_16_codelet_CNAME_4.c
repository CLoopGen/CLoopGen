#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 8; ii++) {
    b[0] = *(a01 + 0) + *(a01 + 4);
    b[1] = *(a01 + 1) + *(a01 + 5);
    b[2] = *(a01 + 2) + *(a01 + 6);
    b[3] = *(a01 + 3) + *(a01 + 7);
    a01 += lda;
    b += 4;
}
}
