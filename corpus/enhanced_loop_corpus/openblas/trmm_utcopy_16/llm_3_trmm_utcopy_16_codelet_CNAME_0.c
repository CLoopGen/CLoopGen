#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 16; ii++) {
    BLASLONG index = ii * lda;
    b[0]  = *(a01 + index + 0);
    b[1]  = *(a01 + index + 1);
    b[2]  = *(a01 + index + 2);
    b[3]  = *(a01 + index + 3);
    b[4]  = *(a01 + index + 4);
    b[5]  = *(a01 + index + 5);
    b[6]  = *(a01 + index + 6);
    b[7]  = *(a01 + index + 7);
    b[8]  = *(a01 + index + 8);
    b[9]  = *(a01 + index + 9);
    b[10] = *(a01 + index + 10);
    b[11] = *(a01 + index + 11);
    b[12] = *(a01 + index + 12);
    b[13] = *(a01 + index + 13);
    b[14] = *(a01 + index + 14);
    b[15] = *(a01 + index + 15);
    b += 16;
}
}
