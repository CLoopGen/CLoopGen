#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 8; ii++) {
    b[0] = *(a01 + 0);
    b[1] = *(a01 + 1);
    b[2] = *(a01 + 2);
    b[3] = *(a01 + 3);
    b[4] = *(a01 + 4);
    b[5] = *(a01 + 5);
    b[6] = *(a01 + 6);
    b[7] = *(a01 + 7);
    b[8] = *(a01 + 8) * 2.0f;
    b[9] = *(a01 + 9) * 2.0f;
    b[10] = *(a01 + 10) * 2.0f;
    b[11] = *(a01 + 11) * 2.0f;
    b[12] = *(a01 + 12) * 2.0f;
    b[13] = *(a01 + 13) * 2.0f;
    b[14] = *(a01 + 14) * 2.0f;
    b[15] = *(a01 + 15) * 2.0f;
    a01 += lda;
    b += 16;
}
}
