#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG indices[6] = {0, 1, 2, 3, 4, 5};
for (ii = 0; ii < 6; ii++) {
    b[0] = ao1[indices[0]];
    b[1] = ao1[indices[1]];
    b[2] = ao1[indices[2]];
    b[3] = ao1[indices[3]];
    b[4] = ao1[indices[4]];
    b[5] = ao1[indices[5]];
    ao1 += lda;
    b += 6;
}
}
