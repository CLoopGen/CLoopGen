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
    BLASLONG offset;
    for (ii = 0; ii < 4; ii++) {
        offset = ii * 4;
        b[offset + 0] = a01[ii];
        b[offset + 1] = a02[ii];
        b[offset + 2] = a03[ii];
        b[offset + 3] = a04[ii];
    }
}
