#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

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

    b[0] = temp1_0;
    b[1] = temp1_1;
    b[2] = temp2_0;
    b[3] = temp2_1;
    b[4] = temp3_0;
    b[5] = temp3_1;
    b[6] = temp4_0;
    b[7] = temp4_1;

    ao1 += 2;
    ao2 += 2;
    ao3 += 2;
    ao4 += 2;
    b += 8;
}
}
