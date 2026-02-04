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
for (ii = 0; ii < 8; ii += 2) {
    float temp1 = *(ao1 + 0), temp2 = *(ao1 + 1);
    float temp3 = *(ao2 + 0), temp4 = *(ao2 + 1);
    float temp5 = *(ao3 + 0), temp6 = *(ao3 + 1);
    float temp7 = *(ao4 + 0), temp8 = *(ao4 + 1);

    b[0] = temp1 * temp2;
    b[1] = temp3 * temp4;
    b[2] = temp5 * temp6;
    b[3] = temp7 * temp8;

    b[4] = temp1 + temp2;
    b[5] = temp3 + temp4;
    b[6] = temp5 + temp6;
    b[7] = temp7 + temp8;

    ao1 += 2;
    ao2 += 2;
    ao3 += 2;
    ao4 += 2;
    b += 8;
}
}
