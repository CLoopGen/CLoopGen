#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_b = b;
BLASLONG local_ii;
for (local_ii = 0; local_ii < 16; local_ii++) {
    for (BLASLONG j = 0; j < 32; j++) {
        local_b[j] = a01[j];
    }
    a01 += lda;
    local_b += 32;
}
b = local_b;
}
