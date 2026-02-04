#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 8; ii++) {
    float temp0 = *(a01 + 0);
    float temp1 = *(a01 + 1);
    float temp2 = *(a01 + 2);
    float temp3 = *(a01 + 3);
    float temp4 = *(a01 + 4);
    float temp5 = *(a01 + 5);
    float temp6 = *(a01 + 6);
    float temp7 = *(a01 + 7);
    b[0] = temp0;
    b[1] = temp1;
    b[2] = temp2;
    b[3] = temp3;
    b[4] = temp4;
    b[5] = temp5;
    b[6] = temp6;
    b[7] = temp7;
    a01 += lda;
    b += 8;
}
}
