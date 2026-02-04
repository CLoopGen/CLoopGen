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
    float temp1_0 = *(a01 + 0);
    float temp1_1 = *(a01 + 1);
    float temp2_0 = *(a02 + 0);
    float temp2_1 = *(a02 + 1);
    float temp3_0 = *(a03 + 0);
    float temp3_1 = *(a03 + 1);
    float temp4_0 = *(a04 + 0);
    float temp4_1 = *(a04 + 1);

    b[0] = temp1_0;
    b[1] = temp1_1;
    b[2] = temp2_0;
    b[3] = temp2_1;
    b[4] = temp3_0;
    b[5] = temp3_1;
    b[6] = temp4_0;
    b[7] = temp4_1;

    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    b += 8;
}
}
