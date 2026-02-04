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
    float temp1, temp2, temp3, temp4;
    for (ii = 0; ii < i; ii++) {
        temp1 = a01[0];
        temp2 = a02[0];
        temp3 = a03[0];
        temp4 = a04[0];
        b[0] = temp1;
        b[1] = temp2;
        b[2] = temp3;
        b[3] = temp4;
        a01++;
        a02++;
        a03++;
        a04++;
        b += 4;
    }
}
