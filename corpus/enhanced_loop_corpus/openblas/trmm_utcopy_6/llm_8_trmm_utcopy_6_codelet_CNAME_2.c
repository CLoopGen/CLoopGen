#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG jj;
for (ii = 0; ii < 4; ii++) {
    for (jj = 0; jj < 4; jj++) {
        b[jj] = ao1[jj];
    }
    ao1 += lda;
    b += 4;
}
}
