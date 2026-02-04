#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 2; ii++) {
    if (ii != 1) {
        b[0] = ao1[0];
        b[1] = ao1[1];
        b[2] = ao1[2];
        b[3] = ao1[3];
    } else {
        b[0] = ao1[0] + 1.0f;
        b[1] = ao1[1] + 1.0f;
        b[2] = ao1[2] + 1.0f;
        b[3] = ao1[3] + 1.0f;
    }
    ao1 += lda;
    b += 4;
}
}
