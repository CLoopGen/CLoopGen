#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
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
for (ii = 0; ii < i; ii++) {
    float temp1_0 = *(ao1 + 0);
    float temp1_1 = *(ao1 + 1);
    float temp2_0 = *(ao2 + 0);
    float temp2_1 = *(ao2 + 1);
    float temp3_0 = *(ao3 + 0);
    float temp3_1 = *(ao3 + 1);
    float temp4_0 = *(ao4 + 0);
    float temp4_1 = *(ao4 + 1);
    float temp5_0 = *(ao5 + 0);
    float temp5_1 = *(ao5 + 1);
    float temp6_0 = *(ao6 + 0);
    float temp6_1 = *(ao6 + 1);
    float temp7_0 = *(ao7 + 0);
    float temp7_1 = *(ao7 + 1);
    float temp8_0 = *(ao8 + 0);
    float temp8_1 = *(ao8 + 1);

    b[0] = temp1_0;
    b[1] = temp1_1;
    b[2] = temp2_0;
    b[3] = temp2_1;
    b[4] = temp3_0;
    b[5] = temp3_1;
    b[6] = temp4_0;
    b[7] = temp4_1;
    b[8] = temp5_0;
    b[9] = temp5_1;
    b[10] = temp6_0;
    b[11] = temp6_1;
    b[12] = temp7_0;
    b[13] = temp7_1;
    b[14] = temp8_0;
    b[15] = temp8_1;

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
