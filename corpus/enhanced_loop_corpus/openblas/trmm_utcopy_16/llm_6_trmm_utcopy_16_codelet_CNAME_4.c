#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 4; ii++) {
    float temp0 = *(a01 + 0);
    float temp1 = *(a01 + 1);
    float temp2 = *(a01 + 2);
    float temp3 = *(a01 + 3);
    b[0] = temp0;
    b[1] = temp1;
    b[2] = temp2;
    b[3] = temp3;
    a01 += lda;
    b += 4;
}
}
