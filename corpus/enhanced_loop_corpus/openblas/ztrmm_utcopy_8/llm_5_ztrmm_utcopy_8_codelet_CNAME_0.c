#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_local = b;
const BLASLONG lda_val = lda;
for (ii = 0; ii < 8; ii++) {
    for (BLASLONG j = 0; j < 16; j++) {
        b_local[j] = a01[j];
    }
    a01 += lda_val;
    b_local += 16;
}
b += 128; // Update original b to point past the written region (simulates same side effect)
}
