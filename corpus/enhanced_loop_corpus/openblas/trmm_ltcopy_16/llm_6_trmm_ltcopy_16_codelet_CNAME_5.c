#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG temp_i;
float *temp_b = b;
float *temp_a01 = a01;
float *temp_a02 = a02;
float *temp_a03 = a03;
float *temp_a04 = a04;

for (ii = 0; ii < i; ii++) {
    temp_b[0] = *(temp_a01 + 0);
    temp_b[1] = *(temp_a01 + 1);
    temp_b[2] = *(temp_a01 + 2);
    temp_b[3] = *(temp_a01 + 3);

    temp_a01 += lda;
    temp_a02 += lda;
    temp_a03 += lda;
    temp_a04 += lda;
    temp_b += 4;
}

b = temp_b;
a01 = temp_a01;
a02 = temp_a02;
a03 = temp_a03;
a04 = temp_a04;
}
