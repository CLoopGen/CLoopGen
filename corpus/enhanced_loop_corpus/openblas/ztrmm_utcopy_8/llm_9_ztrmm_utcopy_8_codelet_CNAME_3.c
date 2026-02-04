#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: process only 4 elements per iteration, double the trip count effect
BLASLONG local_i = i * 2;  // Effectively increasing work but with simpler steps
for (ii = 0; ii < local_i; ii++) {
    b[0] = *(a01 + 0);
    b[1] = *(a01 + 1);
    b[2] = *(a01 + 2);
    b[3] = *(a01 + 3);
    a01 += lda / 2;  // Adjust step assuming lda is even and layout allows
    a02 += lda / 2;
    a03 += lda / 2;
    a04 += lda / 2;
    b += 4;
}
}
