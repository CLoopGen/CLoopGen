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
extern float *ao7;
extern float *ao8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 8; ii++) {
    float temp1 = *(ao1 + 0);
    float temp2 = *(ao1 + 1);
    float temp3 = *(ao2 + 0);
    float temp4 = *(ao2 + 1);
    float temp5 = *(ao3 + 0);
    float temp6 = *(ao3 + 1);
    float temp7 = *(ao4 + 0);
    float temp8 = *(ao4 + 1);
    float temp9 = *(ao5 + 0);
    float temp10 = *(ao5 + 1);
    float temp11 = *(ao6 + 0);
    float temp12 = *(ao6 + 1);
    float temp13 = *(ao7 + 0);
    float temp14 = *(ao7 + 1);
    float temp15 = *(ao8 + 0);
    float temp16 = *(ao8 + 1);

    b[0] = temp1;
    b[1] = temp2;
    b[2] = temp3;
    b[3] = temp4;
    b[4] = temp5;
    b[5] = temp6;
    b[6] = temp7;
    b[7] = temp8;
    b[8] = temp9;
    b[9] = temp10;
    b[10] = temp11;
    b[11] = temp12;
    b[12] = temp13;
    b[13] = temp14;
    b[14] = temp15;
    b[15] = temp16;

    ao1 += 2;
    ao2 += 2;
    ao3 += 2;
    ao4 += 2;
    ao5 += 2;
    ao6 += 2;
    ao7 += 2;
    ao8 += 2;
    b += 16;
}
}
