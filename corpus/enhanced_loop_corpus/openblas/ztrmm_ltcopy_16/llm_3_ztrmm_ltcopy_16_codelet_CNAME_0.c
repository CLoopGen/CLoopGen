#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 16; ii++) {
    BLASLONG index = 0;
    for (BLASLONG j = 0; j < 32; j += 4) {
        b[index++] = *(a01 + j);
        b[index++] = *(a01 + j + 8);
        b[index++] = *(a01 + j + 16);
        b[index++] = *(a01 + j + 24);
    }
    a01 += lda;
    b += 32;
}
}
