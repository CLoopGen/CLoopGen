#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 6; ii++) {
    for (BLASLONG j = 0; j < 6; j++) {
        b[j] = ao1[j * lda];  // Strided access: each column element is accessed with stride 'lda'
    }
    ao1++;
    b += 6;
}
}
