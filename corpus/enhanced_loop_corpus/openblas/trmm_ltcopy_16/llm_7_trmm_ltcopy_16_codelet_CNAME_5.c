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
float *local_b = b;
float *local_a01 = a01;
float *local_a02 = a02;
float *local_a03 = a03;
float *local_a04 = a04;
BLASLONG offset;

for (ii = 0; ii < i; ii++) {
    offset = ii * lda;
    local_b[0] = local_a01[offset + 0];
    local_b[1] = local_a01[offset + 1];
    local_b[2] = local_a01[offset + 2];
    local_b[3] = local_a01[offset + 3];

    local_b += 4;
}

a01 += i * lda;
a02 += i * lda;
a03 += i * lda;
a04 += i * lda;
b += i * 4;
}
