#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 6; ii++) {
    float temp0 = *(ao1 + 0);
    float temp1 = *(ao1 + 1);
    float temp2 = *(ao1 + 2);
    float temp3 = *(ao1 + 3);
    float temp4 = *(ao1 + 4);
    float temp5 = *(ao1 + 5);

    b[0] = temp0;
    b[1] = temp1;
    b[2] = temp2;
    b[3] = temp3;
    b[4] = temp4;
    b[5] = temp5;

    ao1 += lda;
    b += 6;
}
}
