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
for (ii = 0; ii < 1; ii++) {
    float temp1 = *(ao1 + 0) * 2.0f;
    float temp2 = *(ao2 + 0) * 2.0f;
    float temp3 = *(ao3 + 0) * 2.0f;
    float temp4 = *(ao4 + 0) * 2.0f;
    b[0] = temp1 + temp2;
    b[1] = temp3 + temp4;
    b[2] = temp1 - temp2;
    b[3] = temp3 - temp4;
    ao1++;
    ao2++;
    ao3++;
    ao4++;
    b += 4;
}
}
