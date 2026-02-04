#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp1, temp2, temp3, temp4, temp5, temp6;
    for (ii = 0; ii < 6; ii++) {
        temp1 = *(ao1++);
        temp2 = *(ao2++);
        temp3 = *(ao3++);
        temp4 = *(ao4++);
        temp5 = *(ao5++);
        temp6 = *(ao6++);
        b[0] = temp1;
        b[1] = temp2;
        b[2] = temp3;
        b[3] = temp4;
        b[4] = temp5;
        b[5] = temp6;
        b += 6;
    }
}
