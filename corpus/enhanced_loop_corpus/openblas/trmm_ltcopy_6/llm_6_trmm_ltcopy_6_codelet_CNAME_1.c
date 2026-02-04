#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    float temp1 = *(ao1 + 0);
    float temp2 = *(ao1 + 1);
    float temp3 = *(ao1 + 2);
    float temp4 = *(ao1 + 3);
    float temp5 = *(ao1 + 4);
    float temp6 = *(ao1 + 5);

    b[0] = temp1;
    b[1] = temp2;
    b[2] = temp3;
    b[3] = temp4;
    b[4] = temp5;
    b[5] = temp6;

    ao1 += lda;
    ao2 += lda;
    ao3 += lda;
    ao4 += lda;
    ao5 += lda;
    ao6 += lda;
    b += 6;
}
}
