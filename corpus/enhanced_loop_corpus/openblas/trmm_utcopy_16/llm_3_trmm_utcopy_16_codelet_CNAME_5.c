#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG offset;
for (ii = 0; ii < i; ii++) {
    offset = ii * lda;
    b[0] = *(a01 + offset);
    b[1] = *(a01 + offset + 1);
    b[2] = *(a01 + offset + 2);
    b[3] = *(a01 + offset + 3);
    b += 4;
}
}
