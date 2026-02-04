#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *temp_a01 = a01;
    float *temp_a02 = a02;
    float *temp_a03 = a03;
    float *temp_a04 = a04;
    float *temp_b = b;

    for (ii = 0; ii < 4; ii++) {
        temp_b[0] = temp_a01[0];
        temp_b[1] = temp_a01[1];
        temp_b[2] = temp_a02[0];
        temp_b[3] = temp_a02[1];
        temp_b[4] = temp_a03[0];
        temp_b[5] = temp_a03[1];
        temp_b[6] = temp_a04[0];
        temp_b[7] = temp_a04[1];

        temp_a01 += 2;
        temp_a02 += 2;
        temp_a03 += 2;
        temp_a04 += 2;
        temp_b += 8;
    }

    a01 = temp_a01;
    a02 = temp_a02;
    a03 = temp_a03;
    a04 = temp_a04;
    b = temp_b;
}
