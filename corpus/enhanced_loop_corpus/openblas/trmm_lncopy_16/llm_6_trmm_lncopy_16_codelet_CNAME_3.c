#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *temp_a01 = a01;
    float *temp_a02 = a02;
    float *temp_a03 = a03;
    float *temp_a04 = a04;
    float *temp_a05 = a05;
    float *temp_a06 = a06;
    float *temp_a07 = a07;
    float *temp_a08 = a08;
    float *temp_b = b;

    for (ii = 0; ii < i; ii++) {
        temp_b[0] = temp_a01[0];
        temp_b[1] = temp_a02[0];
        temp_b[2] = temp_a03[0];
        temp_b[3] = temp_a04[0];
        temp_b[4] = temp_a05[0];
        temp_b[5] = temp_a06[0];
        temp_b[6] = temp_a07[0];
        temp_b[7] = temp_a08[0];

        temp_a01++;
        temp_a02++;
        temp_a03++;
        temp_a04++;
        temp_a05++;
        temp_a06++;
        temp_a07++;
        temp_a08++;
        temp_b += 8;
    }

    a01 = temp_a01;
    a02 = temp_a02;
    a03 = temp_a03;
    a04 = temp_a04;
    a05 = temp_a05;
    a06 = temp_a06;
    a07 = temp_a07;
    a08 = temp_a08;
    b = temp_b;
}
