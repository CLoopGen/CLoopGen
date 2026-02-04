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
    BLASLONG index = ii * 4;
    b[0] = *(a01 + index);
    b[1] = *(a02 + index);
    b[2] = *(a03 + index);
    b[3] = *(a04 + index);
    b += 4;
}
}
