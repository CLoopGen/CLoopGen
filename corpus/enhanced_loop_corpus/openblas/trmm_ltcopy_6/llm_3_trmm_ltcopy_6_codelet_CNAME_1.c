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
    for (BLASLONG j = 0; j < 6; j++) {
        b[j] = *(ao1 + j * lda);
    }
    ao1 += 1;
    ao2 += 1;
    ao3 += 1;
    ao4 += 1;
    ao5 += 1;
    ao6 += 1;
    b += 6;
}
}
