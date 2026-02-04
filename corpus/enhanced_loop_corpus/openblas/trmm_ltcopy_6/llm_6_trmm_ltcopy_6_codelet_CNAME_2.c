#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp0, temp1, temp2, temp3;
    for (ii = 0; ii < 2; ii++) {
        temp0 = ao1[0];
        temp1 = ao1[1];
        temp2 = ao1[2];
        temp3 = ao1[3];

        b[0] = temp0;
        b[1] = temp1;
        b[2] = temp2;
        b[3] = temp3;

        ao1 += lda;
        b += 4;
    }
}
