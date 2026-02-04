#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *temp_b = b;
    const float *temp_a01 = a01;
    for (ii = 0; ii < 8; ii++) {
        for (BLASLONG j = 0; j < 16; j++) {
            temp_b[j] = temp_a01[j];
        }
        temp_a01 += lda;
        temp_b += 16;
    }
    b = temp_b;
    a01 = (float*)temp_a01;
}
