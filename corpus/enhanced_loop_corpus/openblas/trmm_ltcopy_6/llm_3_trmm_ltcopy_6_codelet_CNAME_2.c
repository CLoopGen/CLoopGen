#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 2; ii++) {
    b[0] = ao1[0 * lda];
    b[1] = ao1[1 * lda];
    b[2] = ao1[2 * lda];
    b[3] = ao1[3 * lda];
    ao1 += lda;
    b += 4;
}
}
