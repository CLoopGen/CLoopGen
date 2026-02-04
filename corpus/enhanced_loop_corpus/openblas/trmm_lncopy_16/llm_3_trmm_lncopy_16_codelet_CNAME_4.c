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
    BLASLONG stride = 1;
    for (ii = 0; ii < 4; ii++) {
        b[ii * stride]       = *(a01 + ii);
        b[(ii + 4) * stride] = *(a02 + ii);
        b[(ii + 8) * stride] = *(a03 + ii);
        b[(ii + 12) * stride]= *(a04 + ii);
    }
}
