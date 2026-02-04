#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp1, temp2, temp3, temp4;
    for (ii = 0; ii < 2; ii++) {
        temp1 = *(ao1++);
        temp2 = *(ao2++);
        temp3 = *(ao3++);
        temp4 = *(ao4++);
        b[0] = temp1;
        b[1] = temp2;
        b[2] = temp3;
        b[3] = temp4;
        b += 4;
    }
}
