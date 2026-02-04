#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 16; ii++) {
    b[0] = *(a01 + 0) + *(a01 + 8);
    b[1] = *(a01 + 1) + *(a01 + 9);
    b[2] = *(a01 + 2) + *(a01 + 10);
    b[3] = *(a01 + 3) + *(a01 + 11);
    b[4] = *(a01 + 4) + *(a01 + 12);
    b[5] = *(a01 + 5) + *(a01 + 13);
    b[6] = *(a01 + 6) + *(a01 + 14);
    b[7] = *(a01 + 7) + *(a01 + 15);
    a01 += lda;
    b += 8;
}
}
