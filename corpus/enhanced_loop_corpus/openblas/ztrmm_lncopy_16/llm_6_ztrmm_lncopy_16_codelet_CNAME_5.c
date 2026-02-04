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
BLASLONG temp_i = i;
float *temp_b = b;
float *temp_a01 = a01;
float *temp_a02 = a02;
float *temp_a03 = a03;
float *temp_a04 = a04;

for (ii = 0; ii < temp_i; ii++) {
    float val1_0 = *(temp_a01 + 0);
    float val1_1 = *(temp_a01 + 1);
    float val2_0 = *(temp_a02 + 0);
    float val2_1 = *(temp_a02 + 1);
    float val3_0 = *(temp_a03 + 0);
    float val3_1 = *(temp_a03 + 1);
    float val4_0 = *(temp_a04 + 0);
    float val4_1 = *(temp_a04 + 1);

    temp_b[0] = val1_0;
    temp_b[1] = val1_1;
    temp_b[2] = val2_0;
    temp_b[3] = val2_1;
    temp_b[4] = val3_0;
    temp_b[5] = val3_1;
    temp_b[6] = val4_0;
    temp_b[7] = val4_1;

    temp_a01 += 2;
    temp_a02 += 2;
    temp_a03 += 2;
    temp_a04 += 2;
    temp_b += 8;
}
}
