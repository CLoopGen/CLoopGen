#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG temp_ii;
float *temp_b = b;
float *temp_a01 = a01;
for (ii = 0; ii < i; ii++) {
    temp_b[0] = *(temp_a01 + 0);
    temp_b[1] = *(temp_a01 + 1);
    temp_b[2] = *(temp_a01 + 2);
    temp_b[3] = *(temp_a01 + 3);
    temp_a01 += lda;
    temp_b += 4;
}
b = temp_b;
a01 = temp_a01;
}
