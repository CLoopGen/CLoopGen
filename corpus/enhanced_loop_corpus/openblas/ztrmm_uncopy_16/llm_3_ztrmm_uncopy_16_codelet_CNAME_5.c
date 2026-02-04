#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    BLASLONG idx_a = ii * 2;
    BLASLONG idx_b = ii * 8;
    b[idx_b + 0] = a01[idx_a + 0];
    b[idx_b + 1] = a01[idx_a + 1];
    b[idx_b + 2] = a02[idx_a + 0];
    b[idx_b + 3] = a02[idx_a + 1];
    b[idx_b + 4] = a03[idx_a + 0];
    b[idx_b + 5] = a03[idx_a + 1];
    b[idx_b + 6] = a04[idx_a + 0];
    b[idx_b + 7] = a04[idx_a + 1];
}
}
