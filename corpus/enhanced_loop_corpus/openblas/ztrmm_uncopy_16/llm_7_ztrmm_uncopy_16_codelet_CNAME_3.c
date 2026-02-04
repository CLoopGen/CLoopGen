#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_local = b;
for (ii = 0; ii < i; ii++) {
    b_local[0]  = a01[0];
    b_local[1]  = a01[1];
    b_local[2]  = a02[0];
    b_local[3]  = a02[1];
    b_local[4]  = a03[0];
    b_local[5]  = a03[1];
    b_local[6]  = a04[0];
    b_local[7]  = a04[1];
    b_local[8]  = a05[0];
    b_local[9]  = a05[1];
    b_local[10] = a06[0];
    b_local[11] = a06[1];
    b_local[12] = a07[0];
    b_local[13] = a07[1];
    b_local[14] = a08[0];
    b_local[15] = a08[1];

    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    a05 += 2;
    a06 += 2;
    a07 += 2;
    a08 += 2;
    b_local += 16;
}
// Introduce a final write to original 'b' with loop-carried dependency removed
// but ensure side effect on global 'b' is preserved after loop
if (i > 0) {
    b = b_local;
}
}
