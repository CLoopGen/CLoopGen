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
        if (ii % 2 == 0) {
            b[0] = a01[0];
            b[1] = a02[0];
        } else {
            b[0] = a03[0];
            b[1] = a04[0];
        }
        b[2] = 0.0f;
        b[3] = 0.0f;
        a01++; a02++; a03++; a04++;
        b += 4;
    }
}
