#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG indices[4] = {0, 1, 2, 3};
for (ii = 0; ii < 4; ii++) {
    b[0] = a01[indices[0]];
    b[1] = a01[indices[1]];
    b[2] = a01[indices[2]];
    b[3] = a01[indices[3]];  // Indirect access via index array (trivial here but pattern-ready)
    a01 += lda;
    b += 4;
}
}
