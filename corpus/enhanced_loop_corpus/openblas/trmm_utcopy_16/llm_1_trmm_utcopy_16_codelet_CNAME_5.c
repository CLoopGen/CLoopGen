#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    for (BLASLONG k = 0; k < 4; k++) {
        b[k] = *(a01 + k);
    }
    a01 += lda;
    b += 4;
}
}
