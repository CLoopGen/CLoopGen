#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_local = b;
for (ii = 0; ii < 4; ii++) {
    b_local[0] = *(a01 + 0);
    b_local[1] = *(a02 + 0);
    b_local[2] = *(a03 + 0);
    b_local[3] = *(a04 + 0);
    a01++;
    a02++;
    a03++;
    a04++;
    b_local += 4;
}
b = b_local;
}
