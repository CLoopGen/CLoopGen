#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[8];
    for (ii = 0; ii < 4; ii++) {
        temp[0] = *(a01 + 0);
        temp[1] = *(a01 + 1);
        temp[2] = *(a01 + 2);
        temp[3] = *(a01 + 3);
        temp[4] = *(a01 + 4);
        temp[5] = *(a01 + 5);
        temp[6] = *(a01 + 6);
        temp[7] = *(a01 + 7);
        b[0] = temp[0];
        b[1] = temp[1];
        b[2] = temp[2];
        b[3] = temp[3];
        b[4] = temp[4];
        b[5] = temp[5];
        b[6] = temp[6];
        b[7] = temp[7];
        a01 += lda;
        b += 8;
    }
}
