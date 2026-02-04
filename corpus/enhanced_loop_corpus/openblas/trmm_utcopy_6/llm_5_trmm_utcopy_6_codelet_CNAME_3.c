#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    if (lda > 0) {
        b[0] = ao1[0];
        b[1] = ao1[1];
        b[2] = ao1[2];
        b[3] = ao1[3];
        ao1 += lda;
        b += 4;
    } else {
        b[0] = 0.0f;
        b[1] = 0.0f;
        b[2] = 0.0f;
        b[3] = 0.0f;
        b += 4;
    }
}
}
