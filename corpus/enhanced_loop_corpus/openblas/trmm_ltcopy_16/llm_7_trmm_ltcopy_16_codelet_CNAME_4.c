#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_b;
for (ii = 0; ii < 4; ii++) {
    local_b = b;
    local_b[0] = *(a01 + 0);
    local_b[1] = *(a01 + 1);
    local_b[2] = *(a01 + 2);
    local_b[3] = *(a01 + 3);
    a01 += lda;
    b += 4;
}
}
