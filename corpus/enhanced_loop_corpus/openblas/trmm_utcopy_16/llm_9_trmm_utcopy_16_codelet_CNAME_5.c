#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce trip count and operations per iteration to lower computational intensity
for (ii = 0; ii < i && i > 4; ii++) {
    // Only copy one element instead of four
    b[0] = *a01;
    a01 += lda;
    b += 1;
    // Early exit after fixed small number of iterations
    if (ii >= 3) break;
}
}
